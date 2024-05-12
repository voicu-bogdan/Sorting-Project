#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "./Sorting Algorithms.c"
#include "./Array Generator.c"

int Algorithm = 0;
int GraphYes = 0;
int initialArraySize = 10000;
int arraySizeStep = 10000;
int finalArraySize = 100000;
int xsize = 1000;

int bruh = 0;

void requestParameters(){
    printf("Graph [1] or time Taken [0]?\n");
    scanf("%d", &GraphYes);
    printf("Select inital Array Size\n");
    scanf("%d", &initialArraySize);
    printf("Select Array Step Size\n");
    scanf("%d", &arraySizeStep);
    printf("Select final Array Size\n");
    scanf("%d", &finalArraySize);
    printf("Select in milliseconds the size of a . on the graph\n");
    scanf("%d", &xsize);
    printf("Random [0], ascending[1], or descending [2] values?\n");
    scanf("%d", &Order);
    printf("Select algorithm to test:\n1. Quicksort\n2. Mergesort\n3. Bubblesort\n4. Insertionsort\n5. Selectionsort\n6. Countingsort\n7. Shakersort\n8. Radixsort\n9. Bogosort\n");
    scanf("%d", &Algorithm);
    return;
}
void generateGraphSegment(int size){
    int osize = size;
    while (size > 0){
        size = size-xsize;
        printf(".");
    }
    printf("\n");
    return;
}

void runTests(int Algorithm){
    // int averageTime[8] = {0, 0, 0, 0, 0, 0,};
    for(int arraySize = initialArraySize; bruh<=10; arraySize = arraySize + arraySizeStep){
        int array[100000];
        GenerateArray(array, arraySize);
        long int timeTaken = 0;
        switch(Algorithm){
            case 1:
                timeTaken = QuickSort(array, arraySize);
                break;
            case 2:
                timeTaken = MergeSort(array, arraySize);
                break;
            case 3:
                timeTaken = BubbleSort(array, arraySize);
                break;
            case 4:
                timeTaken = InsertionSort(array, arraySize);
                break;
            case 5:
                timeTaken = SelectionSort(array, arraySize);
                break;
            case 6:
                timeTaken = CountingSort(array, arraySize);
                break;
            case 7:
                timeTaken = ShakerSort(array, arraySize);
                break;
            case 8:
                timeTaken = RadixSort(array, arraySize);
                break;
            case 9:
                timeTaken = BogoSort(array, arraySize);
                break;
        }
        // printf("%d\n", timeTaken);
        if (GraphYes == 1){
            generateGraphSegment(timeTaken);
        } else {
            printf("(%d, %d)", bruh+1, timeTaken/1000);
            bruh = bruh+1;
        }
    }
} 

int main(){
    srand(time(NULL)); // sets seed for random numbers
    requestParameters();
    runTests(Algorithm);
    return 0;
}