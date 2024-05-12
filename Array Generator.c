#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Order = 0;

int RandomNumber(){
    int x = rand()%100+1;
    return x;
}

void GenerateArray(int *buf, int arraySize){
    if (Order = 0){
    for (int i=0; i<arraySize; i++){
        buf[i]=RandomNumber();
    }
    } else if(Order = 2){
        for(int i=0; i<arraySize; i++){
        buf[i]=arraySize-i;
        }
    } else if(Order = 1){
        for(int i=0; i<arraySize; i++){
        buf[i]=i-arraySize;
        }
    }
}
