#include"init.h"

void *nakli_malloc(size_t size){
    block *block=request_block(size);
    return block+1;
}

void nakli_free(void *ptr){
    block *block=ptr-blockSize;
    block->free=1;
}