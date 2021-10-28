#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>

int main(void){
	int ret=fork();
	if(ret>0){
		int parentPID=getppid();
		int currentPID=getpid();
		printf("CURRENT_PROCESS_PID:-%d\nPARENT_PROCESS_PID:-%d\n",currentPID,parentPID );
	}
	else if(ret ==0){ 
		sleep(20); 
		printf("child is created Successfully\n");
		int parentPid=getppid();
		int childPid=getpid();
		printf("CHILD_PROCESS_PID:-%d\nPARENT_PROCESS_PID:-%d\n",childPid,parentPid ); 
	}
	else{
		printf("unsuccessfull!");
	}
	return 0;
}