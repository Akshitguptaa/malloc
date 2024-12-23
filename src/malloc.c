#include"init.h"
#include"malloc.h"

void printList(){
    block *temp=head;
    printf("block info-->\n");
    while(temp){
        printf("block at %p--> Size~ %zu, Free~ %d\n",(void *)temp,temp->size,temp->free);
        temp=temp->next;
    }
}

void *nakli_malloc(size_t size){
    block *block=request_block(size);
    return block+1;
}

void nakli_free(void *ptr){

    // block *block=ptr-blockSize;
    // block->free=1;
    if (!ptr) return;

    printList();
    block *curr=ptr-blockSize;
    curr->free=1;

    // coalescing from front
    if(curr->next && curr->next->free){
        curr->size+=blockSize+ curr->next->size;
        curr->next =curr->next->next;
    }

    //coalescing from back
    block *temp = head;
    while(temp){
        if(temp->next==curr && temp->free){
            temp->size+= blockSize+curr->size;
            temp->next=curr->next;
            break;
        }
        temp = temp->next;
    }
    printList();
}