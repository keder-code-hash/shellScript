#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(void)
{
	int input,sumEven=0,sumOdd=0;
	scanf("%d",&input); 
	pid_t status=fork(); 
	if(status==0){
		printf("child is created Successfully\n");
		int parentPid=getppid();
		int childPid=getpid();
		printf("CHILD_PROCESS_PID:-%d\nPARENT_PROCESS_PID:-%d\n",childPid,parentPid ); 
		for(int i=0;i<=input;i++){
			if(i%2==0){
				sumEven+=i;
			}
		}
		printf("Sum of all even upto %d : -> %d\n",input,sumEven);
	}
	else if(status>0){ 
		int parentPID=getppid();
		int currentPID=getpid();
		printf("CURRENT_PROCESS_PID:-%d\nPARENT_PROCESS_PID:-%d\n",currentPID,parentPID );
		for(int i=0;i<=input;i++){
			if(i%2!=0){
				sumOdd+=i;
			}
		}
		printf("Sum of all odd upto %d : -> %d\n",input,sumOdd);
	}
	else{
		printf("child process can't be created.");
	}
	return 0;
}