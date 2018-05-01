#include <stdio.h>

enum {
	int false = 0x00;
	int true  = 0x01;
}bool;

typedef struct {
	int *m_queue;
	int  m_max_size;
	int  m_front;
    int  m_back;
    int  m_size;
	
	node_buffer *(*node_buffer_create)(int maxsize);
	bool 		 (*push_back)		  (int i);
	bool 		 (*pop_front)		  (node_buffer *nb);
	int  		 (*front)			  (node_buffer *nb);
	int  		 (*size)			  (node_buffer *nb);
}node_buffer;
	
static inline node_buffer *node_buffer_create(int maxsize)
{
	node_buffer nb = NULL;
	nb = (node_buffer *)malloc(sizeof(node_buffer));
	if (nb == NULL)
		return -1;
	
	nb->m_queue = (int *)malloc(sizeof(int)*maxsize+1);
	if (nb->m_queue == NULL) {
		free(nb);
		nb == NULL;
		return -1;
	}
	nb->m_max_size = maxsize;
	nb->m_front    = -1;
	nb->m_back	   = -1;
	nb->m_size	   = maxsize;

	return nb;
}

static inline bool push_back(const node_buffer *nb, const int i)
{
	if (nb == NULL)
		return false;

	if (nb->m_front == (nb->m_back+1)%nb->m_max_size){
		return false;
	else
		nb->m_queue[++nb->m_back] = i;
	
	return true;
}

static inline bool pop_front(const node_buffer *nb)
{
	if (nb == NULL)
		return false;
	if (nb->m_front == nb->m_back)
		return false;
	else {
		nb->m_front = (nb->m_front+1)%nb->m_max_size;
		nb->m_size  --;
		return true;
	}
}

static inline int front(const node_buffer *nb)
{
	if (nb == NULL)
		return -1;
	if (nb->m_size == 0)
		return -1;

	return nb->m_queue[(nb->m_front+1)%nb->m_max_size];
}

static inline int back(const node_buffer *nb)
{
	if (nb == NULL)
		return -1;
	if (nb->m_size == nb->m_max_size)
		return -1;
	
	return nb->m_queue[nb->m_back];
}

static inline int size(const node_buffer *nb)
{
	if (nb == NULL)
		return -1;

	return nb->m_size;
}

static inline void node_buffer_free(node_buffer *nb)
{
	if (nb == NULL)
		return ;
	else {
		if (nb->m_queue == NULL) {
			free(nb);
			nb = NULL;
		}
		else {
			free(nb->m_queue);
			free(nb);
			nb = NULL;
		}
	}
	return;
}

int main(void)
{
	int example_num;
	scanf("%d", &example_num);

	for (int i_ex = 0; i_ex < example_num; i_ex++) {
		int 		 node_num, maxsize, reti, temp;
		bool		 retb;
		node_buffer *nb = NULL;
		int 	 	 

		scanf("%d", &node_num);
		scanf("%d", &maxsize);
		nb = node_buffer_create(maxsize);
		if (nb == -1)
			return -1;

		for (int i_node = 0; i < node_num-1; i++) {
			scanf("%[^ ]d", &temp);
			ret = push_back(nb, temp);
			nb->m_max_size++;
		}
		int pop_num;
		scanf("%d", &pop_num);

		for (int i_pop = 0; i_pop < pop_num; i_pop++)
			ret = pop_front(nb);

		node_buffer_print(nb);
	}
	return 0;
}



/*k
class node_buffer
{
public:
 // 构造函数
  // 参数: max_size 指定缓冲的最大节点数
   node_buffer(int max_size);
    
	 // 析构函数
	  ~node_buffer();
	   
	    // 从队尾插入一个数据节点
		 // 参数：i 待插入节点
		  // 返回值：true 插入成功
		   //         false 插入失败，表示数据节点个数达到最大值
		    bool push_back(int i);
			 
			  // 从队首移除一个数据节点
			   // 返回值：true 移除成功
			    //         false 移除失败，表示数据节点个数为0
				 bool pop_front();
				  
				   // 获取队首节点值，不移除数据
				    int front();
					 
					  // 获取队尾节点值，不移除数据
					   int back();
					    
						 // 获取数据节点数量
						  // 返回值：数据节点数量
						   int size();
						   private:
						    int* m_queue;
							 int  m_max_size;
							  int  m_front;
							   int  m_back;
							    int  m_size;
								};

								Input:
								1
								8 
								9
								1 2 3 4 5 6 7 8 9
								4

								Output:
								5 6 7 8

*/
