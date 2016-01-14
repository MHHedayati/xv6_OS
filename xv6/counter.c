#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int
main(int argc, char *argv[])
{
	
	int count = 0;
	//struct proc *p;
	int pid = fork();
	if(pid == 0){
		while(count < 20){
			printf(0, "%d \n",count);
			count = count + 1;
			sleep(100);
		}		
	}else{
		sleep(1000);
		saveProc(pid);
		//getPCB(pid);
		//writePCB();
		sleep(1000);
	}
	
	
  	exit();
}
