#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<fcntl.h>
int main()
{
    unlink("/home/student/Desktop/pipe/pipe84133");
    int k=mkfifo("/home/student/Desktop/pipe/pipe84133",0777);
    if(k==0)
    {
        printf("pipe created\n");
        char str[100]="Techno";
        int fd=open("/home/student/Desktop/pipe/pipe84133",O_WRONLY);
        int b=write(fd,str,strlen(str));
        printf("size:- %d",b);
        // printf("success");
    } 
    else
    {
        printf("can not be created\n");
    }
    return 0;
}