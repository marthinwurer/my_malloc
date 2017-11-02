#include <stdio.h>

#include "my_malloc.h"

int main(int argc, char * argv[]){
	(void) argc;
	(void) argv;
	printf( "Hello World\n");
	printf("void* size: %ld\n", sizeof(void*));
	printf("size_t* size: %ld\n", sizeof(size_t));

	int * data = my_malloc(100 * sizeof(int));
	for( int ii = 0; ii < 100; ii++){
		if (ii % 15 == 0){
			data[ii] = -11;
		}
		else if (ii % 5 == 0){
			data[ii] = -1;
		}
		else if (ii % 3 == 0){
			data[ii] = ii;
		}
		else{
			data[ii] = ii;
		}
	}
	for( int ii = 0; ii < 100; ii++){
		printf("%d\n", data[ii]);
	}
}

