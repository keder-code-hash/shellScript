#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){

	int fd[2];
	char inp[100]; 
	char parentString[100];
	scanf("%s",inp); 
	strcpy(parentString,inp);
	pipe(fd);
	int status=fork();
	if(status==0){ 
		close(fd[0]);
		write(fd[1],inp,sizeof(inp));
	}
	else if(status>0){ 
		char a[100];
		close(fd[1]);
		read(fd[0],a,sizeof(a)); 
		int stringSize=strlen(a);
		char *revString=(char *)malloc(stringSize);
		int i=0;
		for(i=0;i<stringSize;i++){ 
			revString[i]=inp[stringSize-1-i];
		} 
		printf("%s",revString); 
	}
	else{
		 
	}

return 0;

}