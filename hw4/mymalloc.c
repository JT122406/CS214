#include <stdio.h>
#include <stdlib.h>



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

}


void myfree(void* ptr){

}


void* myrealloc(void* ptr, size_t size){

}


void mycleanup(){

}