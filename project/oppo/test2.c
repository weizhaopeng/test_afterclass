#include <stdio.h>
#include <stdlib.h>

typedef struct array {
	long *set;
	long  num;
} array;

static inline long del_ab_num(array *darr, const long del_ab) {
	int i;
	for(i = 0; i < darr->num; i++){
		if (darr->set[i] == del_ab)
			return darr->num;
	}
	darr->set[i] = del_ab;
	darr->num++;
	return darr->num;
}
			

int main(void) {
	int num;
	scanf("%d", &num);

	int  buf[num], del = 0;
	long sum = 0, del_ab = 0, s = 0;
	
	for (int i = 0; i < num; i++) {
		scanf("%d", buf+i);
		fflush(stdin);
	}

	long max = 0, min = abs(buf[1]+buf[0]-abs(buf[0]-buf[1]));
	long uset[num*(num-1)];
	array darr = {
		.set = uset,
		.num = 0
	};

	for (int i = 0, k = 0; i < num; i++) {
		for(int j = i+1; j < num; j++) {
			sum = buf[i]+buf[j];
			del = abs(buf[i]-buf[j]);	
			del_ab = abs(sum-del);

			if (del_ab > max)
				max = del_ab;
			if (del_ab < min)
				min = del_ab;
			
			s = del_ab_num(&darr, del_ab);
		}
	}

	printf("%ld\n", min+max+s);
	return 0;
}


				



