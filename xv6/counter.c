#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

// Per-process state
struct proc {
  uint sz;                     // Size of process memory (bytes)
  pde_t* pgdir;                // Page table
  char *kstack;                // Bottom of kernel stack for this process
  enum procstate state;        // Process state
  int pid;                     // Process ID
  struct proc *parent;         // Parent process
  struct trapframe *tf;        // Trap frame for current syscall
  struct context *context;     // swtch() here to run process
  void *chan;                  // If non-zero, sleeping on chan
  int killed;                  // If non-zero, have been killed
  struct file *ofile[NOFILE];  // Open files
  struct inode *cwd;           // Current directory
  char name[16];               // Process name (debugging)
};

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
			sleep(10);
		}		
	}else{
		sleep(100);
		struct proc *ip = malloc(sizeof(struct proc));
		saveProc(pid, ip);
		//getPCB(pid);
		//writePCB();
		sleep(100);
	}
	
	
  	exit();
}



//int fd;
	//fd = open("save.proc", O_CREATE|O_RDWR);
  	//if(fd < 0){
    	//	printf(stdout, "error: creat big failed!\n");
   	// 	exit();
  	//}
	//int i;
  	//for(i = 0; i < MAXFILE; i++){
    	//	((int*)buf)[0] = i;
    	//	if(write(fd, buf, 512) != 512){
      	//	printf(stdout, "error: write big file failed\n", i);
      	//	exit();
    	//	}
  	//}
	//close(fd);
