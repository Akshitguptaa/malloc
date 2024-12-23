#ifndef INIT_H
#define INIT_H
#include"malloc.h"
#include"stdint.h"

void initMemory();
void freeMemory();
block *request_block(size_t size);
block *findFreeBlock(block **last, size_t size);
#endif