#include <stdio.h>
#include <stdlib.h>

#define CAPICITY 1000000

char heap[CAPICITY] = {0};


void myinit(int allocAlg){
    switch (allocAlg)
    {
    case 0:  //first fit
        /* code */
        break;
    case 1:  //next fit
        /* code */
        break;
    case 2:  //best fit
        /* code */
        break;
    default:
        break;
    }
}


void* mymalloc(size_t size){
    if (size == 0)
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