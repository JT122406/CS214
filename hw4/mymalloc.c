#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
    int size;
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
    int totalSize = ceil(size/8);  //total in heap to allocate for
    if (size == 0 || totalSize > CAPICITY)
        return NULL;  //Return Null
    else
        return(begining(totalSize));
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