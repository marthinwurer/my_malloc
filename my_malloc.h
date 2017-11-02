#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>

void * my_malloc(size_t size);

void my_free(void * old);
