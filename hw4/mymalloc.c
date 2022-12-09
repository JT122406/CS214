#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "mymalloc.h"

#define CAPICITY 125000

int allocType = 0;
int actual_size = 0;

struct mem_buffer{
    struct mem_buffer *next;
    struct mem_buffer *prev;
    int size;
   unsigned char *buffer;
};

typedef struct mem_buffer mem_buffer;

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
        allocType = 0;
        break;
    case 1:  //next fit
        allocType = 1;
        break;
    case 2:  //best fit
        allocType = 2;
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
    switch (allocType)
    {
    case 0:
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
                    //to do that you should check to see if the remaining space is larger than sizeof(mem_buffer) + 8
                    //if not keep that memory with the block being allocated
                    mem_buffer *New_one;
                    New_one->next = Current->next;
                    New_one->prev = Current->prev;
                    New_one->size = Current->size - actual_size - sizeof(mem_buffer);
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
        break;
    case 1:
            
        break;
    case 2:
                
        break;
    }
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
    while (FreeList != NULL)
    {
        free(FreeList->prev);
        FreeList = FreeList->next;
    }
    free(FreeList);
    while (Current != NULL)
    {
        free(Current->prev);
        Current = Current->next;
    }
    free(Current);
}