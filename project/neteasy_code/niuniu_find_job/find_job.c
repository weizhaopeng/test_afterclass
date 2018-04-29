#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

/*定义数据结构*/
typedef struct {
	uint32_t difficulty;
	uint32_t salary;
}jobs;

typedef struct {
	uint32_t ability;
}people;

static inline int find_job(const jobs *job, const int job_num, const people *pp)
{
	uint32_t sal = 0;

	for (int i = 0; i < job_num; i++) {
		if (pp->ability >= job[i].difficulty) {
			sal = job[i].salary;
		}
	}
	return sal;
}

int main()
{	
	int job_num, people_num;
	scanf("%d%d", &job_num, &people_num);

	jobs   job[job_num];
	for (int i = 0; i < job_num; i++)
		scanf("%d%d", &job[i].difficulty, &job[i].salary);

	int 	 ret;
	people   pp[people_num];
	uint32_t buf[1000];
	ret = read(1, buf, 1000*4);
	if (ret = -1)
		return -1;
	for (int i = 0; i < people_num; i++)
		sscanf(buf, "%d", &pp[i].ability);
	
	uint32_t salary;
	for (int peo = 0; peo < people_num; peo++) {
		salary = find_job(job, job_num, pp+peo);
		if (salary > 0)
			printf("%d\n", salary);
		else
			printf("no job\n");
	}
	return 0;
}

