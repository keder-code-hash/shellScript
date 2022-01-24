#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex;
int counter=10;
void *fun(void *i){
	int temp;
	temp=*(int *)i;
	while(1){
		// wait
		sem_wait(&mutex);
		counter+=temp;
		printf("thread :%d ,counter val: %d\n",temp,counter);

		sem_post(&mutex);
		// signal
		usleep(1000);
		//suspend a thread for a specific microsecond
	}
}

int main()
{
	
	pthread_t th1,th2;

	int val1=1,val2=-1;

	printf("main started\n");
	pthread_attr_t attribute;
	pthread_attr_init(&attribute);
	pthread_attr_setschedpolicy(&attribute,SCHED_RR);

	sem_init(&mutex,0,1);
	// sem_init(address of sem,int pshared,int initial_numtexVal)
	/*

		If  pshared  has the value 0, then the semaphore is shared between the threads of a process, and should be located
        at some address that is visible to all threads (e.g., a global variable, or a variable  allocated  dynamically  on
        the heap).
        If  pshared  has the value 0, then the semaphore is shared between the threads of a process, and should be located
        at some address that is visible to all threads (e.g., a global variable, or a variable  allocated  dynamically  on
        the heap).

	*/

	pthread_create(&th1,(void *)&attribute,fun,(void *)&val1);
	pthread_create(&th2,(void *)&attribute,fun,(void *)&val2);
	pthread_join(&th1,NULL);
	pthread_join(&th2,NULL);

	sem_destroy(&mutex);
	// sem_destroy() destroys the unnamed semaphore at the address pointed to by sem.
	printf("main ended\n"); 
}