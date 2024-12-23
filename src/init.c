#include"init.h"
#include <errno.h>
#include<stdlib.h>
#define MINREQ 0x20000

void *memory = NULL;
size_t endpos = 0;

void initMemory(){
    // checking for maximum memory 
    // PTRDIFF_MAX is maximum value in ptr diff type 
    size_t required=PTRDIFF_MAX;

    while(memory==NULL){

        memory=malloc(required);
        // checking if minumum requirement is achieved
        if(required < MINREQ){
            if(memory){
                free(memory);
            }
            // error handing when there is no enough memory
            printf("Cannot allocate enough memory\n");
            exit(ENOMEM);
        }
        // dividing the 2 in every iteration
        required>>=1;
    }
}

void freeMemory(){
    free(memory);
}

void *head=NULL;
block *findFreeBlock(block **last, size_t size){
    block *temp=head;
    // checking for free block with temp->size>=size(required)
    while(temp && !(temp->free && temp->size>=size)){
        *last=temp;
        temp=temp->next;
    }
    return temp;
}

block *request_block(size_t size){
    block *last =NULL;
    block *block=findFreeBlock(&last, size);
    if(block){
        block->free = 0;
        return block;
    }
    block=memory+endpos;
    endpos+=blockSize+size;
    // if no free block present allocate new memory
    if(last){
        last->next=block;
    }

    else{
        head=block;
    }
    block->free=0;
    block->next=NULL;
    block->size=size;
    return block;
}