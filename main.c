#include"src/malloc.h"
#include"src/init.h"
#include<stdio.h>
// #include<stdlib.h>
// #include<cstring>
#include<string.h>

int main(){
    initMemory();
    char *data=(char*)nakli_malloc(100);

    // if(!data){
    //     printf("memory not allocated!! \n");
    //     return 1;
    // }
    
    printf("Allocation successfull!! \n");
    strcpy(data,"malloc data <hello world!!>");
    printf("%s\n", data);

    nakli_free(data);
    freeMemory();
}
