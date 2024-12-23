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

void func3(){
    initMemory();

    printf("using malloc-> \n");
    int *arr=(int *)nakli_malloc(5 * sizeof(int));
    for(int i=0;i<5;i++) {
        arr[i] = i * 10;
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("using realloc-> \n");
    arr=(int *)nakli_realloc(arr,10*sizeof(int));
    for(int i=5;i<10;i++) {
        arr[i] = i * 10;
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("using calloc-> \n");
    int *arr1 = (int *)nakli_calloc(5, sizeof(int));
    for(int i=0;i<5;i++) {
        printf("%d ",arr1[i]);
    }
    printf("\n");

    nakli_free(arr);
    nakli_free(arr1);

    freeMemory();
}

int main(){
    // func1();
    // func2();
    func3();
}