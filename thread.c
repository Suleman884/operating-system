#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int chunk_size=100;

int array[3000];

void * add(void* s){

	int start=(int)s;

	int sum=0;

	for(int i=start;i<start+chunk_size;i++)
	
	{
		sum=sum+array[i];
	}
	return (void *)sum;
}
int main()
{
	int sum=0;

	void *thread1,*thread2,*thread3,*thread4,*thread5,*thread6,*thread7,*thread8,*thread9,*thread10;

	for(int i=0;i<3000;i++)
	{
		array[i]=i;
	}

	pthread_t pthread1,pthread2,pthread3,pthread4,pthread5,pthread6,pthread7,pthread8,pthread9,pthread10;
//creating threads..
	pthread_create(&pthread1,NULL,add,(void *)0);
	pthread_create(&pthread2,NULL,add,(void *)300);
	pthread_create(&pthread3,NULL,add,(void *)600);
	pthread_create(&pthread4,NULL,add,(void *)900);
	pthread_create(&pthread5,NULL,add,(void *)1200);
	pthread_create(&pthread6,NULL,add,(void *)1500);
	pthread_create(&pthread7,NULL,add,(void *)1800);
	pthread_create(&pthread8,NULL,add,(void *)2100);
	pthread_create(&pthread9,NULL,add,(void *)2400);
	pthread_create(&pthread10,NULL,add,(void *)2700);
//joining threads
	pthread_join(pthread1,(void **)&thread1);
	pthread_join(pthread2,(void **)&thread2);
	pthread_join(pthread3,(void **)&thread3);
	pthread_join(pthread4,(void **)&thread4);
	pthread_join(pthread5,(void **)&thread5);
	pthread_join(pthread6,(void **)&thread6);
	pthread_join(pthread7,(void **)&thread7);
	pthread_join(pthread8,(void **)&thread8);
	pthread_join(pthread9,(void **)&thread9);
	pthread_join(pthread10,(void **)&thread10);
//adding the desire result of threads
	sum=sum + (int)thread1+(int)thread2+(int)thread3+(int)thread4+(int)thread5+(int)thread6+(int)thread7+(int)thread8+(int)thread9+(int)thread10;
	printf("Sum is : %d\n",sum);
	return 0;
}

