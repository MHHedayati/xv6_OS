//writes sz  		
		printf(fd,"sz:%d\n", ip->sz);
		//writes pgdir
		
		//writes kstack
		
		//writes state		
		printf(fd,"state:%s\n", ip->state);
		//writes pid		
		printf(fd,"pid:%d\n", ip->pid);
		//writes trapframe		
		printf(fd,"trapframe:\n");
		printf(fd,"edi:%d\n", ip->tf->edi);
		printf(fd,"esi:%d\n", ip->tf->esi);
		printf(fd,"ebp:%d\n", ip->tf->ebp);
		printf(fd,"oesp:%d\n", ip->tf->oesp);
		printf(fd,"ebx:%d\n", ip->tf->ebx);
		printf(fd,"edx:%d\n", ip->tf->edx);
		printf(fd,"ecx:%d\n", ip->tf->ecx);
		printf(fd,"eax:%d\n", ip->tf->eax);
		printf(fd,"gs:%d\n", ip->tf->gs);
		printf(fd,"padding1:%d\n", ip->tf->padding1);
		printf(fd,"fs:%d\n", ip->tf->fs);
		printf(fd,"padding2:%d\n", ip->tf->padding2);
		printf(fd,"es:%d\n", ip->tf->es);
		printf(fd,"padding3:%d\n", ip->tf->padding3);
		printf(fd,"ds:%d\n", ip->tf->ds);
		printf(fd,"padding4:%d\n", ip->tf->padding4);
		printf(fd,"trapno:%d\n", ip->tf->trapno);
		printf(fd,"err:%d\n", ip->tf->err);
		printf(fd,"eip:%d\n", ip->tf->eip);
		printf(fd,"cs:%d\n", ip->tf->cs);
		printf(fd,"padding5:%d\n", ip->tf->padding5);
		printf(fd,"eflags:%d\n", ip->tf->eflags);
		printf(fd,"esp:%d\n", ip->tf->esp);
		printf(fd,"ss:%d\n", ip->tf->ss);
		printf(fd,"padding6:%d\n", ip->tf->padding6);
		//writes context
		printf(fd,"context:\n");
		printf(fd,"edi:%d\n", ip->context->edi);
		printf(fd,"esi:%d\n", ip->context->esi);
		printf(fd,"ebx:%d\n", ip->context->ebx);
		printf(fd,"ebp:%d\n", ip->context->ebp);
		printf(fd,"eip:%d\n", ip->context->eip);
		//writes chan
		
		//writes killed
		printf(fd,"killed:%d\n", ip->killed);
		//writes file
		
		//writes inode
		printf(fd,"inode:\n");
		printf(fd,"dev:%d\n", ip->cwd->dev);
		printf(fd,"inum:%d\n", ip->cwd->inum);
		printf(fd,"ref:%d\n", ip->cwd->ref);
		printf(fd,"flags:%d\n", ip->cwd->flags);
		printf(fd,"type:%d\n", ip->cwd->type);
		printf(fd,"major:%d\n", ip->cwd->major);
		printf(fd,"minor:%d\n", ip->cwd->minor);
		printf(fd,"nlink:%d\n", ip->cwd->nlink);
		printf(fd,"size:%d\n", ip->cwd->size);
		int i;			
		for(i=0;i<NDIRECT+1;i++){
			printf(fd,"%d:%d",i,ip->cwd->addrs[i]);	
		}
