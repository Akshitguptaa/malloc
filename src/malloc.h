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

void *nakli_realloc(void *ptr, size_t new_size);

void *nakli_calloc(size_t num,size_t size);

// void printList();

extern void *head;
#endif