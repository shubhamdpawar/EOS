#include<stdio.h>
#include<pthread.h>
int count =10;
pthread_mutex_t mutexcount;
pthread_mutexattr_t attrcount;
void square(void ) ;

void* inc_thread(void*arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutexcount);
		count++;
		square();
		printf("Inc thread : %d",count);
		pthread_mutex_unlock(&mutexcount);
	}
}
void sqaure()
{
	pthread_mutex_lock(&mutexcount);
	count=count*count;
	pthread_mutex_unlock(&mutexcount);
}
void* dec_thread(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutexcount);
		count--;
		printf("dec-thread:%d",count);
		pthread_mutex_unlock(&mutexcount);
	}
}
int main()
{
	pthread_t incID,decID;
	pthread_mutexattr_init(&attrcount);
	pthread_mutex_init(&mutexcount,&attrcount);
	pthread_mutexattr_settype(&attrcount,PTHREAD_MUTEX_RECURSIVE);
	pthread_create(&incID,NULL,inc_thread,NULL);
	pthread_create(&decID,NULL,dec_thread,NULL);
	pthread_join(incID,NULL);
	pthread_join(decID,NULL);
	pthread_mutex_destroy(&mutexcount);
	printf("Program-ENdedd\n");
	return 0;
}
