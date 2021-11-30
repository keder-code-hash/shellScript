#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<fcntl.h>
int main(){
		int size;
		scanf("%d",&size);
		int arr[size];
		for(int i=0;i<size;i++){
			scanf("%d",&arr[i]);
		}
		
		
		unlink("/home/student/Desktop/pipe/pipe8413312");	
		int k=mkfifo("/home/student/Desktop/pipe/pipe8413312",0777);
		printf("pipe created\n");
 		
		int fd=open("/home/student/Desktop/pipe/pipe8413312",O_WRONLY);
		int b=write(fd,arr,sizeof(arr));
		close(fd);
		printf("size:- %d",b);  
		printf("success");  

		sleep(2);
		int fd1=open("/home/student/Desktop/pipe/pipe84133121",O_RDONLY);
		int arr2[10];
		int m=read(fd1,arr2,sizeof(arr2));

		for(int i=0;i<m/sizeof(int);i++){
			printf("%d ",arr2[i]);
		}
	return 0;

}
