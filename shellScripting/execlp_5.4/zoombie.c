#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void)
{
	pid_t status=fork(); 
	if(status==0){
		printf("child is created Successfully\n");
		int parentPid=getppid();
		int childPid=getpid();
		printf("CHILD_PROCESS_PID:-%d\nPARENT_PROCESS_PID:-%d\n",childPid,parentPid ); 
		exit(0);
	}
	else if(status>0){ 
		sleep(3);
		int t;
		wait(&t);
		int parentPID=getppid();
		int currentPID=getpid();
		printf("CURRENT_PROCESS_PID:-%d\nPARENT_PROCESS_PID:-%d\n",currentPID,parentPID );
		if(t==0){
			printf("Child process is executed.code :-> %d",WEXITSTATUS(t));
		}
	}
	else{
		printf("child process can't be created.");
	}
	return 0;
}