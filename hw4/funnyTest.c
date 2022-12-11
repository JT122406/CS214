#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "mymalloc.h"

int main(int argc, char *argv[])
{
	//char *array;
	//int i;

	/*
	 * must be first call in the program
	 */
	myinit(2);
	//PrintFreeList();

	//PrintFreeList();

	int* test = mymalloc(24);
	char*array = mymalloc(56);
    int *fart = mymalloc(200);
	int *shart = mymalloc(48);
	int *fart2 = mymalloc(200);
	//for(int i=0; i < 9; i++)
	//{
	//	array[i] = 'a' + i;
	//}
	//array[9] = 0;

	//printf("here is my nifty new string: %s\n",array);	


    //PrintFreeList();
	//myfree(test);
	myfree(array);
	myfree(shart);
	int* test2 = mymalloc(20);
	//myfree(fart);
	//myfree(array);

	//myfree(array);

	//PrintFreeList();
	//myfree(fart);
	//printf("\n");
	PrintFreeList();
	//int* test2 = mymalloc(72);
	//
	//PrintFreeList();

	/*array = MyMalloc(10);
	if(array == NULL)
	{
		fprintf(stderr,"call to MyMalloc() failed\n");
		fflush(stderr);
		exit(1);
	}

	for(i=0; i < 9; i++)
	{
		array[i] = 'a' + i;
	}
	array[9] = 0;

	printf("here is my nifty new string: %s\n",array);

	MyFree(array);
    */
	return(0);
}