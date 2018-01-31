#include others
#include <data_store.h>
#include <stream_parse.h>



int main(int argc, char **argv)
{
	//step1: 解析参数，参数应该包括需要读取的文件名或者一个网络地址
	for(int i=1 ; i<argc ; i++)
	{
		stream_input_parse(*(argv=i));

		
	step2: 对象初始化，初始化stream buffer和data store
	step3: stream input流程处理，包括将处理好的word存进stream buffer
	step4: 依次将stream buffer中的word存进data store中
	step5: 对data store进行排序，然后获取个数最多的10个word，打印
备注：有空可以考虑一下，为什么对数据进行多份存储，以及为什么对框架进行这种划分？
}
