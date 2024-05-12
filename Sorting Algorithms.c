#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// quicksort V
// mergesort V
// bubblesort V
// insertionsort V
// selectionsort V
// countingsort V
// shakersort V
// radixsort V
// bogosort V

// supplemental functions

int checkSorted(int array[], int arraySize){
    int isSorted = 1;
    for(int i=0; i<arraySize-1; i++){
        if (array[i]>array[i+1]){
            isSorted = 0;
        }
    }
    return isSorted;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// sorting algorithms

int QuickSort(int array[], int arraySize){
    long int startTime = clock();
    int stack[100000];

    int top = -1;

    stack[++top] = 0;
    stack[++top] = arraySize - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];

        int pi = partition(array, low, high);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
    long int endTime = clock();
    long int runTime = endTime - startTime;
    return(runTime);
}

void merge(int array[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

int MergeSort(int array[], int arraySize){
    long int startTime = clock();
    for (int currSize = 1; currSize <= arraySize - 1; currSize *= 2) {
        for (int leftStart = 0; leftStart < arraySize - 1; leftStart += 2 * currSize) {
            int mid = (leftStart + currSize - 1 < arraySize - 1) ? leftStart + currSize - 1 : arraySize - 1;
            int rightEnd = (leftStart + 2 * currSize - 1 < arraySize - 1) ? leftStart + 2 * currSize - 1 : arraySize - 1;
            merge(array, leftStart, mid, rightEnd);
        }
    }
    long int endTime = clock();
    long int runTime = endTime-startTime;
    return(runTime);
}

int BubbleSort(int array[], int arraySize){
    long int startTime = clock();
    for (int i=0; i<arraySize; i++){
        for (int j=0; j<arraySize-1; j++){
            if (array[j]> array[j+1]){
                int aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }
    long int endTime = clock();
    long int runTime = endTime-startTime;
    return(runTime);
}

int InsertionSort(int array[], int arraySize) {
    long int startTime = clock();
    
    for (int i = 1; i < arraySize; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    
    long int endTime = clock();
    long int runTime = endTime - startTime;
    return runTime;
}

int SelectionSort(int array[], int arraySize) {
    long int startTime = clock();
    
    for (int i = 0; i < arraySize - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arraySize; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
    
    long int endTime = clock();
    long int runTime = endTime - startTime;
    return runTime;
}

int CountingSort(int array[], int arraySize) {
    long int startTime = clock();

    int max = array[0];
    for (int i = 1; i < arraySize; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int count[max + 1];
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < arraySize; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    int output[arraySize];
    for (int i = arraySize - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < arraySize; i++) {
        array[i] = output[i];
    }

    long int endTime = clock();
    long int runTime = endTime - startTime;
    return runTime;
}

int ShakerSort(int array[], int arraySize) {
    long int startTime = clock();

    int left = 0;
    int right = arraySize - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        for (int i = left; i < right; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (array[i] < array[i - 1]) {
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                swapped = true;
            }
        }
        left++;
    }

    long int endTime = clock();
    long int runTime = endTime - startTime;
    return runTime;
}

int RadixSort(int array[], int arraySize) {
    long int startTime = clock();

    int max = array[0];
    for (int i = 1; i < arraySize; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[arraySize];
        int count[10] = {0};

        for (int i = 0; i < arraySize; i++) {
            count[(array[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arraySize - 1; i >= 0; i--) {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (int i = 0; i < arraySize; i++) {
            array[i] = output[i];
        }
    }

    long int endTime = clock();
    long int runTime = endTime - startTime;
    return runTime;
}

int  BogoSort(int array[], int arraySize){
    long int startTime = clock();
    int isSorted = 0;
    while (isSorted == 0){
        int firstPosition = rand()%arraySize+1;
        int secondPosition = rand()%arraySize+1;
        int aux = array[firstPosition];
        array[firstPosition] = array[secondPosition];
        array[secondPosition] = aux;
        isSorted = checkSorted(array, arraySize);
    }
    long int endTime = clock();
    long int runTime = endTime-startTime;
    return(runTime);
}