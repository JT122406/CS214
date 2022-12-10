#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//#include "mymalloc.h"

#define CAPICITY 125000

int allocType = 0;
int actual_size = 0;

struct mem_buffer{
    struct mem_buffer *next;  //pointer to next block of memory allocated
    struct mem_buffer *prev;  //pointer to previous block of memory allocated
    int size;  //size of the block of memory allocated
    unsigned char *buffer;  //pointer to the block of memory allocated
};

typedef struct mem_buffer mem_buffer;

mem_buffer *FreeList;
mem_buffer *Current;

static unsigned char BigBuffer[CAPICITY];

void createList(){
    FreeList = (mem_buffer *)BigBuffer;  //Creates the list
    FreeList->next = NULL;  //Sets the next pointer to null
    FreeList->prev = NULL;  //Sets the previous pointer to null
    FreeList->size = sizeof(BigBuffer) - sizeof(mem_buffer);  //Sets the size of the whole buffer as free
    FreeList->buffer = (unsigned char*)(BigBuffer + sizeof(mem_buffer));  //point to whole buffer
}

void myinit(int allocAlg){
    createList();
    allocType = allocAlg;
    printf("size of bigbuff: %p\n", BigBuffer);
}

mem_buffer* addNode(mem_buffer *node, mem_buffer *node2){
    if (node->prev != NULL)
        node->prev->next = node2->next;
    if (node->next != NULL)
        node->next->prev = node2->prev;
    return node2;
}


void* firstFit(int actual_size){
        printf("made it to the first one\n");
        Current = FreeList;
        printf("made it to the second one\n");
    Current = FreeList;


    while(Current != NULL){
        printf("made it to the third one\n");
                if(Current->size >= actual_size){
                    printf("made it to the fourth one\n");

                    if(Current->size == actual_size){  
                        //addNode(Current, Current);


                        if (Current->prev != NULL)
                            Current->prev->next = Current->next;
                        if (Current->next != NULL)
                            Current->next->prev = Current->prev;

                        return Current->buffer;
                        //if the size is the exact same as the free space
                        //you take the space out of the free list but it does not need to be split up
                    }
                    else{
                        mem_buffer *New_one = NULL;
                        //This splits the current block into a new smaller one that maintains connectivity with the rest of the list
                        //in future implement check to see if the remaining space is large enough
                        //to handle the buffer and at least 8 bytes of data
                        //to do that you should check to see if the remaining space is larger than sizeof(mem_buffer) + 8
                        //if not keep that memory with the block being allocated
                        New_one->next = Current->next;
                        New_one->prev = Current->prev;

                        New_one->size = Current->size - actual_size - sizeof(mem_buffer);
                        New_one->buffer =(unsigned char*)(Current->buffer + actual_size + sizeof(mem_buffer));
                        Current->size = actual_size;

                        //addNode(Current, New_one);

                        if(Current->prev != NULL)  //If first node in list
                            Current->prev->next = New_one;
                        if(Current->next != NULL)  //If last node in list
                            Current->next->prev = New_one;

                        return Current->buffer;  //Pointer to buffer
                    }

                }
        Current = Current->next;

    }
    return NULL;
}

void* nextFit(int actual_size){
    Current = FreeList;
    return NULL;
}

void* bestFit(int actual_size){
    Current = FreeList;
    mem_buffer *tempnode = NULL;
    while(Current != NULL){
    if (actual_size <= Current->size)
        if ((tempnode==NULL) || tempnode->size > Current->size)
            tempnode = Current;
    }
    
    mem_buffer *New_one = NULL;
    //This splits the current block into a new smaller one that maintains connectivity with the rest of the list

/*
    addNode(Current, New_one);
    New_one->buffer = (unsigned char*)(Current->buffer + actual_size + sizeof(mem_buffer));
    Current->buffer = (unsigned char*)(Current->buffer - actual_size - sizeof(mem_buffer));
    return New_one->buffer;
    */
}


void* mymalloc(size_t size){
    if(size == 0  || size > CAPICITY)
        return NULL;

    actual_size = size;
    if(size % 8)
        actual_size = size + (size % 8); 


    switch (allocType)
    {
    case 0:
        return firstFit(actual_size);
    case 1:
        return nextFit(actual_size);
    case 2:
        return bestFit(actual_size);
    }
    return NULL;
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

void PrintFreeList(){
    Current = FreeList;
    while(Current != NULL){
        printf("block: %p\n", Current);
        printf("size: %d\n",Current->size);
        printf("next: %p\n", Current->next);
        printf("prev: %p\n", Current->prev);
        printf("buffer: %p\n", Current->buffer);
        Current = Current->next;


    }
}