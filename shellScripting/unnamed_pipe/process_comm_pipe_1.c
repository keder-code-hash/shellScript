#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){

	int fd[2]; 
	int size=0; 
	int inp[2];
	scanf("%d",&inp[0]);
	scanf("%d",&inp[1]);
	pipe(fd);
	int status=fork();
	if(status==0){
		printf("child is created\n"); 
		write(fd[1],inp,sizeof(inp));
		
		sleep(1); 
		int *r=(int *)malloc(1*sizeof(int));
		read(fd[0],(void * )r,sizeof(r));
		printf("value from child process: %d\n",r[0]); 
	}
	else if(status>0){
		printf("parent process\n");
		int a[2];  
		read(fd[0],a,sizeof(a)); 
		int res=1,i=0;
		for(i=0;i<inp[1];i++){
			res*=inp[0];
		} 
		int *ar=(int *)malloc(1*sizeof(int));
		ar[0]=res;  
		write(fd[1],ar,sizeof(ar)); 
	}
	else{
		printf("Unsuccessfull creation of child");
	}

return 0;

}
