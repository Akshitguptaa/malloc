#include"src/malloc.h"
#include"src/init.h"
#include<stdio.h>
// #include<stdlib.h>
// #include<cstring>
#include<string.h>

void func1(){
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

void func2(){
    initMemory();
    char *data1 =(char*)nakli_malloc(100);
    char *data2=(char*)nakli_malloc(200);
    char *data3=(char*)nakli_malloc(150);

    // fragmenting data 
    nakli_free(data2);
    nakli_free(data3);
    nakli_free(data1);

    freeMemory();
}

int main(){
    // func1();
    func2();
}