#include"init.h"
#include"malloc.h"
#include<math.h>
#include<string.h>

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

    // printList();
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
    // printList();
}

void *nakli_calloc(size_t num,size_t size) {    
    size*=num;

    void *ptr = nakli_malloc(size);
    if(!ptr){
        return ptr;
    }
        char *byte= ptr;
        for(size_t i=0;i<size;i++){
            byte[i]=0;
        }


    return ptr;
}

void *nakli_realloc(void *ptr,size_t size){
    // printList();
    if(!ptr){
        return nakli_malloc(size);
    }
        // when size==NULL
    if(size==0){
        nakli_free(ptr);
        return NULL;
    }

    block *curr=ptr-blockSize;

    if(curr->size>=size){
        if(curr->next && curr->next->free){
            curr->size=size;
            return ptr;
        }
    }

    void *temp=nakli_malloc(size);
    if(temp){
        // purane data to new mei 
        memcpy(temp,ptr,fmin(curr->size,size));


        nakli_free(ptr);
    }
    // printList();
    return temp;
}
