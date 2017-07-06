#include <stdlib.h>
#include "Task.h"

TCB *createThread(char *name, void (*task)(void), uint32_t size){
	if(size < 128){
		size  = 128;
	}

	TCB *tcb = (TCB *)malloc(sizeof(TCB));
	tcb->name = name;
	tcb->task = task;
	tcb->stackSize = size;
	tcb->stackBegin = (uint32_t *)malloc(size);
	tcb->execReturnCode = 0xfffffff9;
	tcb->stackPointer = (uint32_t *)(tcb->stackBegin + size);
	tcb->stackPointer -= 20;
	*(uint32_t *)&tcb->stackPointer[0] = 0x11111111;
	*(uint32_t *)&tcb->stackPointer[4] = 0x22222222;
	*(uint32_t *)&tcb->stackPointer[8] = 0x33333333;
	*(uint32_t *)&tcb->stackPointer[12] = 0x44444444;
	*(uint32_t *)&tcb->stackPointer[16] = 0x55555555;
	*(uint32_t *)&tcb->stackPointer[20] = 0x66666666;
	*(uint32_t *)&tcb->stackPointer[24] = 0x77777777;
	*(uint32_t *)&tcb->stackPointer[28] = 0x88888888;
	*(uint32_t *)&tcb->stackPointer[32] = 0x99999999;
	*(uint32_t *)&tcb->stackPointer[36] = 0xaaaaaaaa;
	*(uint32_t *)&tcb->stackPointer[40] = 0xbbbbbbbb;
	*(uint32_t *)&tcb->stackPointer[44] = 0xcccccccc;
	*(uint32_t *)&tcb->stackPointer[48] = 0xdddddddd;
	*(uint32_t *)&tcb->stackPointer[52] = 0xeeeeeeee;
	*(uint32_t *)&tcb->stackPointer[56] = (void (*)(void))task;
	*(uint32_t *)&tcb->stackPointer[60] = 0x21000000;
	return tcb;
}

TCB *initKernel(char *mainThreadName){
	TCB *tcb = (TCB *)malloc(sizeof(TCB));
	tcb->name = mainThreadName;
	tcb->stackBegin = NULL;
	tcb->stackSize = 0;
	return tcb;
}
