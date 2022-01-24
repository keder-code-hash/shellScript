#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>

static void *test(void *t_str){
	int i=1;
	for(i=1;i<=10;i++){
		printf("counter: %d\n",i);
		sleep(1);
	}
}
int main(){
	pthread_t th;
	printf("---main started---\n");
	int status=pthread_create(&th,NULL,test,NULL);
	printf("status code : %d\n",status);
	sleep(4);
	printf("--main ended--"); 
}
