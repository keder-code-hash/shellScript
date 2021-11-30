#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<fcntl.h>
int main(){
		sleep(5);
		int fd1=open("/home/student/Desktop/pipe/pipe8413312",O_RDONLY);
		int arr1[10];
		int a=read(fd1,(void *)arr1,sizeof(arr1));
 
		int size=a/sizeof(int);
		printf("size:-%d\n",size);


		for(int i=0;i<size;i++){
			for(int j=i+1;j<size;j++){
				if(arr1[j] < arr1[i]){
					int temp=arr1[i];
					arr1[i]=arr1[j];
					arr1[j]=temp;
				}
			}
		}
		for(int i=0;i<size;i++){
			printf("%d ",arr1[i]);
		}

		close(fd1);


		unlink("/home/student/Desktop/pipe/pipe84133121");	
		int k=mkfifo("/home/student/Desktop/pipe/pipe84133121",0777);
		printf("pipe created\n");
		int fd2=open("/home/student/Desktop/pipe/pipe84133121",O_WRONLY);
		int x=write(fd1,arr1,sizeof(int)*size);
		printf("Wrirting success.Size- %d",x);
		return 0;
}
