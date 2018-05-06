/*在H.264视频编码标准中，编码帧由NALU头和NALU主体组成，
 *其中NALU头由一个字节组成。在实际编码时，在每个NAL前添加起始码 0x000001
 *，解码器在码流中检测到起始码，当前NAL结束。
 *为了防止NAL内部出现0x000001的数据，在编码完一个NAL时，如果检测出有连续两个0x00字节，就在后面插入一个0x03。
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct store_node{
	unsigned char buf;
	int			  next_tab;
}store_node;

typedef struct store {
	store_node *sn;
	store_node *sn_cp;
	int			length;
	int			start_num;
}store;

static inline int find_sps_in_h264(store *sto, int N){
	int         table = 0, length ;
	store_node *start = sto->sn;
	for (int i = 0; i < N; i++, length++) {
		if (sto->sn[i].buf == 0x00 && table == 0) {
			if (sto->sn[i+1].buf == 0x00 && sto->sn[i+2].buf == 0x01) {
				table  = 1;
				start  = &sto->sn[i+3];
				i	   +=2;
				length = 0;
			}
		}
		if (sto->sn[i].buf == 0x00 && table == 1) {
			if (sto->sn[i+1].buf == 0x00 && sto->sn[i+2].buf == 0x03) {
				sto->sn[i+1].next_tab = sto->sn[i+2].next_tab;
				i+=2;
				for (int k = i; k < N; k++)
					sto->sn[k] = sto->sn[k+1];
				length++;
			}
			if (sto->sn[i+1].buf == 0x00 && sto->sn[i+2].buf == 0x01) {
				sto->sn[i-1].next_tab = -1;
				sto->sn = start;
				return length;
			}

		}
		if (sto->sn[i].next_tab == -1) {
			sto->sn = start;
			return length+1;
		}
	}
}

int main(int argc, char **argv) {
	int test_num;
	scanf("%d", &test_num);
	
	store *sto[test_num], *store_x;
	store_node *stn[test_num];
	for (int i = 0; i < test_num; i++) {
		int q_length;
		scanf("%d", &q_length);
		
		store_x			   =(store *)malloc(sizeof(store));
		store_x->sn	       = store_x->sn_cp = (store_node*)calloc(1, sizeof(store_node)*q_length);
		store_x->length    = q_length;
		store_x->start_num = 0;

		for (int j = 0; j < q_length; j++) {
			fflush(stdin);
			scanf("%x", &(store_x->sn[j].buf));
			store_x->sn[j].next_tab = j+1;
		}
		store_x->sn[q_length-1].next_tab = -1;

		store_x->length = find_sps_in_h264(store_x, q_length);
		sto[i] = store_x;
	}

	for (int j = 0; j < test_num; j++) {
		for (int k = 0; k < sto[j]->length ; k++)
			printf("%x ", sto[j]->sn[k].buf);

		if (sto[j]->sn != NULL) {
			free(sto[j]->sn_cp);
			free(sto[j]);
		}
		printf("\n");
	}
}




