#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>

static void *test(void *t_str){
	long t_id;
	t_id=(long *)t_str;
	printf("calling thread id : %ld\n",t_id);
	pthread_exit(NULL);
}
int main(){
	pthread_t th[5]; 
	printf("---main started---\n");
	long i;
	for(i=0;i<5;i++){
		int status=pthread_create(&th[i],NULL,test,(void *)i); 
		pthread_join(th[i],NULL);
		// if second params is not null then it look for the value,that has returned by target thread(i.e. pthread_exit(status)).
		// If the target thread is cancelled previously then PTHREAD_CANCELED is placed  in  the  location
       	// pointed to by retval.
	} 
	printf("--main ended--"); 
	pthread_exit(NULL);
}
