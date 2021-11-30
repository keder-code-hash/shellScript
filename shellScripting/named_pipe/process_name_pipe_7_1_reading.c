#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<fcntl.h>
int main(){
    sleep(5);
    int fd1=open("/home/student/Desktop/pipe/pipe84133",O_RDONLY);
    char str1[20];
    int a=read(fd1,(void *)str1,strlen(str1));
    printf("size:-%d\n",a);
    printf("%s",str1);
    return 0;
}