#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPICITY 125000

char heap[CAPICITY] = {0};

int allocType = 0;

struct pointers
{
    bool isFree;
    void* ptr;
};

struct mem_buffer{
    struct mem_buffer *next;
    struct mem_buffer *next;
    char *buffer;
};

typedef struct pointers pointers;

void myinit(int allocAlg){
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


void* mymalloc(size_t size){
    if (size == 0 || size > CAPICITY)
        return NULL;  //Return Null

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