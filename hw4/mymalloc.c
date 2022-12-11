#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//#include "mymalloc.h"

#define CAPICITY 125000

int allocType = 0;
int actual_size = 0;
int ThisisDumb = 0;

struct mem_buffer{
    struct mem_buffer *next;  //pointer to next block of memory allocated
    struct mem_buffer *prev;  //pointer to previous block of memory allocated
    int size;  //size of the block of memory allocated
    char status;  //status of the block of memory allocated
    unsigned char *buffer;  //pointer to the block of memory allocated
};

typedef struct mem_buffer mem_buffer;

mem_buffer *FreeList;
mem_buffer *Current;
mem_buffer *New_one;
mem_buffer *Free_one;
mem_buffer *FreeList_but_for_next_fit;


static unsigned char BigBuffer[CAPICITY];

void createList(){
    FreeList = (mem_buffer *)BigBuffer;  //Creates the list
    FreeList->next = NULL;  //Sets the next pointer to null
    FreeList->prev = NULL;  //Sets the previous pointer to null
    FreeList->size = CAPICITY - sizeof(mem_buffer);  //Sets the size of the whole buffer as free
    FreeList->buffer = (unsigned char*)(BigBuffer + sizeof(mem_buffer));  //point to whole buffer
    FreeList->status = '0';  //Sets the status to free
    FreeList_but_for_next_fit = FreeList;
}

void myinit(int allocAlg){
    createList();
    allocType = allocAlg;
    printf("size of bigbuff: %p\n", BigBuffer);
}



void split(mem_buffer *Current, int actual_size){
    if(Current->size-actual_size<=sizeof(mem_buffer)){
        //if the remaining space is too small to handle the buffer and at least 8 bytes of data
        //then keep that memory with the block being allocated
        return;
    }
    mem_buffer *New_one = (void*) (Current + 1) + actual_size;
    New_one->size =    Current->size - actual_size - sizeof(mem_buffer);
    Current->size = actual_size;
    New_one->status = '0';
    New_one->buffer = (void*) (New_one + 1);
    New_one->next = Current->next;
    New_one->prev = Current;
    if(Current->next)
        New_one->next->prev = New_one;
    Current->next = New_one;

}




void* firstFit(int actual_size){
   if(FreeList == NULL) return NULL;
    mem_buffer *pointer = FreeList;
    
    while (pointer != NULL)
    {
        if (pointer->status == '0' && pointer->size >= actual_size)
        {
            if (pointer->size>actual_size) split(pointer, actual_size);
            pointer->status='1';
            return pointer->buffer;  
        }
        pointer = pointer->next;
    }
    return NULL;
}

void* nextFit(int actual_size){
    if(FreeList==NULL) return NULL;

    while (FreeList_but_for_next_fit != NULL)
    {
        if (FreeList_but_for_next_fit->status == '0' && FreeList_but_for_next_fit->size >= actual_size)
        {
            if (FreeList_but_for_next_fit->size>actual_size) split(FreeList_but_for_next_fit, actual_size);
            FreeList_but_for_next_fit->status='1';
            return FreeList_but_for_next_fit->buffer;  
        }
        FreeList_but_for_next_fit = FreeList_but_for_next_fit->next;
    }
    mem_buffer *pointer = FreeList;

    
    while (pointer != NULL)
    {
        if (pointer->status == '0' && pointer->size >= actual_size)
        {
            if (pointer->size>actual_size) split(pointer, actual_size);
            pointer->status='1';
            FreeList_but_for_next_fit = pointer->next;
            return pointer->buffer;  
        }
        pointer = pointer->next;
    }





    //Current = FreeList;
    return NULL;
}

void* bestFit(int actual_size){
    if(FreeList==NULL) return NULL;
    mem_buffer *ptr=FreeList;
    mem_buffer *min=NULL;
    while(!(ptr==NULL)){
        if(ptr->status=='0' && ptr->size>=actual_size){
            min=ptr;
            break;
        }
        ptr=ptr->next;
    }
    if(min==NULL) return NULL;
    ptr=min->next;
    while(ptr!=NULL){
        if(ptr->status=='0' && ptr->size>=actual_size && ptr->size<min->size)
            min=ptr;
        ptr=ptr->next;
    }
    if(min->size>actual_size)
        split(min,actual_size);
        min->status='1';
        return min->buffer;
}


void* mymalloc(size_t size){
    if(size == 0  || size > CAPICITY)
        return NULL;

    actual_size = size;
    if(size % 8)
        actual_size = size + (8-(size % 8)); 


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

void merge(mem_buffer *pointer){
pointer->size = pointer->size + pointer->next->size + sizeof(mem_buffer);
pointer->next = pointer->next->next;
if(pointer->next)
    pointer->next->prev = pointer;
}

void myfree(void* ptr){
    mem_buffer *pointer = FreeList;
    if (ptr == NULL)return;//Do nothing

    while(pointer != NULL){
        if(pointer->buffer == ptr){
            pointer->status = '0';
            if(pointer->next && pointer->next->status == '0')
                merge(pointer);
            if (pointer->prev && pointer->prev->status == '0')
                merge(pointer->prev);
            return;
        }
        pointer = pointer->next;
    }

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
    if(size % 8)
    actual_size = size + (8-(size % 8)); 
    mem_buffer *pointer = FreeList;
    while(pointer != NULL){
        if(pointer->buffer == ptr){
            split(pointer, actual_size);
            break;
        }
        pointer = pointer->next;
    }

    
}


void mycleanup(){
    while (FreeList != NULL)
    {
        myfree(FreeList->prev);
        FreeList = FreeList->next;
    }
    myfree(FreeList);
   // while (Current != NULL)
   // {
     //   free(Current->prev);
       // Current = Current->next;
    //}
    //free(Current);
}

void PrintFreeList(){
    Current = FreeList;
    while(Current != NULL){
        printf("block: %p\n", Current);
        printf("size: %d\n",Current->size);
        printf("next: %p\n", Current->next);
        printf("prev: %p\n", Current->prev);
        printf("buffer: %p\n", Current->buffer);
        printf("status: %c\n", Current->status);
        Current = Current->next;
    }
}