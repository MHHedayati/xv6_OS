#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"


#define NDIRECT 12
struct inode {
  uint dev;           // Device number
  uint inum;          // Inode number
  int ref;            // Reference count
  int flags;          // I_BUSY, I_VALID
  short type;         // copy of disk inode
  short major;
  short minor;
  short nlink;
  uint size;
  uint addrs[NDIRECT+1];
};

struct trapframe {
  uint edi;
  uint esi;
  uint ebp;
  uint oesp;
  uint ebx;
  uint edx;
  uint ecx;
  uint eax;
  ushort gs;
  ushort padding1;
  ushort fs;
  ushort padding2;
  ushort es;
  ushort padding3;
  ushort ds;
  ushort padding4;
  uint trapno;
  uint err;
  uint eip;
  ushort cs;
  ushort padding5;
  uint eflags;
  uint esp;
  ushort ss;
  ushort padding6;
};

struct context {
  uint edi;
  uint esi;
  uint ebx;
  uint ebp;
  uint eip;
};

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
	int pid = fork();
	if(pid == 0){
		while(count < 20){
			printf(0, "%d \n",count);
			count = count + 1;
			sleep(10);
		}		
	}else{
		char* mem =0;
		sleep(100);
	
		struct proc *ip = malloc(sizeof(struct proc));
		pde_t* pgdir = malloc(sizeof(pde_t));
		ip->pgdir = pgdir;
		char *kstack = malloc(sizeof(char));
		ip->kstack = kstack;
		struct trapframe *tf = malloc(sizeof(struct trapframe));
		ip->tf = tf;
		struct context *context = malloc(sizeof(struct context));
		ip-> context = context;
		
		int a = saveProc(pid, ip, mem);
		printf(1,"\n%d",*ip->pgdir);
		if(a)
			printf(1,"PCB copy acquired");
		int fd; 
		fd = open("proc", O_CREATE|O_RDWR);
		write(fd,ip,sizeof(struct proc));
		close(fd);
			printf(1,"PCB written successfully");
		sleep(100);
		fd = open("proc", O_RDONLY);
		read(fd, ip, sizeof(struct proc));
		close(fd);
		sleep(200);
		loadProc(ip);
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
