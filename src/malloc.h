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

void *head=NULL;

block *findFreeBlock(block **last, size_t size)
{
    block *temp=head;
    // checking for free block with temp->size>=size(required)
    while(temp && !(temp->free && temp->size>=size)){
        *last=temp;
        temp=temp->next;
    }
    return temp;
}

#endif