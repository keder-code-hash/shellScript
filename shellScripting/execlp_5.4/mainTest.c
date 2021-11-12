#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(void)
{
	char inp[100]; 
	char t[100];
	strcpy(t,"t.out");
	fgets(inp,100,stdin);
	pid_t status=fork();
	printf("%d",status);
	if(status==0){
		printf("child is created Successfully\n");
		int parentPid=getppid();
		int childPid=getpid();
		printf("CHILD_PROCESS_PID:-%d\nPARENT_PROCESS_PID:-%d\n",childPid,parentPid ); 
		 
		if(strcmp(inp,"exit")==10){
			printf("exit");
			exit(0);
		}
		if(strcmp(inp,"t.out")==10){
			execlp("/home/keder/shellscrpit/shellScripting/execlp_5.4/t.out",inp,NULL); 
		}  
	}
	else if(status>0){ 
		int parentPID=getppid();
		int currentPID=getpid();
		printf("CURRENT_PROCESS_PID:-%d\nPARENT_PROCESS_PID:-%d\n",currentPID,parentPID );

	}
	else{
		printf("child process can't be created.");
	}
	return 0;
}