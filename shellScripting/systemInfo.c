#include<stdio.h>
#include<stdlib.h>
#include<sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/vfs.h>

struct utsname s2;
struct sysinfo s1;
struct statfs s3;


int main(){
	char *ptr="./";
	int q=uname(&s2);
	int r=sysinfo(&s1);
	int statFs=statfs(ptr,&s3);


	if(q==0){
		printf("System name: %s\n",s2.sysname);
		printf("Version: %s\n",s2.version);
		printf("Release: %s\n",s2.release);
		printf("Machine: %s\n",s2.machine);
	}
	if(r==0){
		unsigned long usedSpace=(s1.totalram-s1.freeram)/(1024*1024);
		printf("Total RAM: %luMB\n",(s1.totalram)/(1024*1024));
		// printf("total free memory: %luMB\n",(s1.freeram)/(1024*1024));
		// printf("total user ram: %luMB\n",usedSpace);
		printf("Total Swap Space: %luMB\n",(s1.totalswap)/(1024*1024));
	}
	if(statFs==0){
		printf("Total Size of partition: %luGB\n",((s3.f_bsize)*(s3.f_blocks))/(1024*1024*1024));
	}
	return 0;
}