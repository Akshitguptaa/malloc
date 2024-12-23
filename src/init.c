#include"init.h"
#include <errno.h>
#define MINREQ 0x20000

void *memory = NULL;

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
