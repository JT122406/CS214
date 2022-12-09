#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "mymalloc.h"

#define CAPICITY 125000

char heap[CAPICITY] = {0};

int allocType = 0;
int actual_size = 0;
/*
struct pointers
{
    bool isFree;
    void* ptr;
};

typedef struct pointers pointers;

pointers *createPointers(bool isFree, void* ptr){
    pointers *new = malloc(sizeof(pointers));
    new->isFree = isFree;
    new->ptr = ptr;
    return new;
}
*/
struct mem_buffer{
    struct mem_buffer *next;
    struct mem_buffer *prev;
    int size;
   unsigned char *buffer;
};

typedef struct mem_buffer mem_buffer;
/*
mem_buffer *createmem_buffer(int nodes){
    mem_buffer *new = malloc(sizeof(mem_buffer));
    new->size = nodes;
    new->buffer = (char*)malloc(nodes);
    new->next = NULL;
    new->prev = NULL;
    return new;
}
*/
mem_buffer *FreeList;
mem_buffer *Current;

unsigned char BigBuffer[CAPICITY];


void myinit(int allocAlg){
    FreeList = (mem_buffer *)BigBuffer;
    FreeList->next = NULL;
    FreeList->prev = NULL;
    FreeList->size = sizeof(BigBuffer) - sizeof(mem_buffer);
    FreeList->buffer = (unsigned char*)(BigBuffer + sizeof(mem_buffer));
    switch (allocAlg)
    {
    case 0:  //first fit
        /* code */
        allocType = 0;
        break;
    case 1:  //next fit
        /* code */
        allocType = 1;
        break;
    case 2:  //best fit
        /* code */
        allocType = 2;
        break;
    default:
        break;
    }
}

void* begining(int nodes){
    switch (allocType)
    {
    case 0:  //first fit (Linear Search)
        for (int i = 0; i < CAPICITY; i++)
        {
            if (heap[i] == 0)
                for (int j = 0; j < nodes; j++)
                {
                    if (heap[1+j] != 0)
                    {
                        i +=j;
                        break;
                    }
                    if (j == nodes-1)
                    {
                        for (int k = 0; k < nodes; k++)  //mark them as allocated
                        {
                            heap[i+k] = 1;
                        }
                        return &heap[i];  //return pointer to the first node
                    }
                }
            
        }
        return NULL;  //Return Null
        break;
    case 1:  //next fit
        
        
        break;
    case 2:  //best fit
        
        
        break;
    default:
        break;
    }
}


void* mymalloc(size_t size){
    if(size = 0)
    return NULL;
    actual_size = size;
    if(size % 8)
    actual_size = size + (size % 8); 
    if(allocType == 0){
        Current = FreeList;
        while(Current != NULL){
            if(Current->size >= actual_size){
                if(Current->size == actual_size){
                    Current->prev->next = Current->next;
                    Current->next->prev = Current->prev;
                    return Current->buffer;
                    //if the size is the exact same as the free space
                    //you take the space out of the free list but it does not need to be split up
                }
                else{
                    //This splits the current block into a new smaller one that maintains connectivity with the rest of the list
                    //in future implement check to see if the remaining space is large enough
                    //to handle the buffer and at least 8 bytes of data
                    mem_buffer *New_one;
                    New_one->next = Current->next;
                    New_one->prev = Current->prev;
                    New_one->size = Current->size - actual_size;
                    New_one->buffer =(unsigned char*)(Current->buffer + actual_size + sizeof(mem_buffer));
                    Current->size = actual_size;
                    if(Current->prev != NULL)
                    Current->prev->next = New_one;
                    if(Current->next != NULL)
                    Current->next->prev = New_one;
                    return Current->buffer;
                }
            }
        Current = Current->next;
        }
        return NULL;
    }
    if(allocType == 1){}
    if(allocType == 2){}
}


void myfree(void* ptr){
    if (ptr == NULL)
        return;  //Do nothing
    

}


void* myrealloc(void* ptr, size_t size){
    if (ptr == NULL && size == 0)
        return NULL;  //Return Null
    else if (ptr == NULL)
    {
        mymalloc(size);
        return;
    }else if(size == 0)
    {
        myfree(ptr);
        return;
    }
    
    

}


void mycleanup(){

}