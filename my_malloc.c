#include "my_malloc.h"


/**
	Want everything to be 64-byte alligned (size of cache line)

*/

typedef struct malloc_header_s{
	struct malloc_header_s * next; // 8
	struct malloc_header_s * prev; // 16
	size_t size;


} malloc_header;

//////////////////////////////////////////////
// GLOBALS
//////////////////////////////////////////////

size_t page_size = 0; // should automatically be set to zero, but who wants to bet that?


void * my_malloc(size_t size){

	(void) size;
	
	if ( page_size == 0){
		// get the page size
		page_size = sysconf(_SC_PAGE_SIZE);
		printf("page size: %ld\n", page_size);
	}
	
	// pa=mmap(addr, len, prot, flags, fildes, off);
	void * addr = mmap(NULL,
						page_size - 1,
						PROT_READ | PROT_WRITE,
						MAP_ANONYMOUS | MAP_PRIVATE,
						-1,
						0);

	printf("address: %p\n", addr);
	perror("mmap");


	return addr;
}

void my_free(void * old){
	(void) old;
	
}

