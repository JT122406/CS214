#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void myinit(int allocAlg);
void* mymalloc(size_t size);
void myfree(void* ptr);
void* myrealloc(void* ptr, size_t size);
void mycleanup();
void PrintFreeList();

#endif