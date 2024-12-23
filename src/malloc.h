#ifndef MALLOC_H
#define MALLOC_H
#include<stdio.h>

typedef struct block
{
    size_t size;
    struct block *next;
    int free;
}block;
#define blockSize sizeof(block)
void *nakli_malloc(size_t size);
void nakli_free(void* ptr);
extern void *head;
#endif