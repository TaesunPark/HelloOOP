//
// Created by taesunpark on 2022/09/29.
//
#include<stdio.h>
#include<stdlib.h>

//int * mergeSort(i)
void mergeSort(int * array);
void rMergeSort(int * array, int left, int right);
void merge(int * array, int left, int mid, int right);
void printArray(int * array);
int n;

int main(){

    scanf("%d", &n);
    int array[n];

    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }

    mergeSort(array);

    printArray(array);
}

void mergeSort(int * array){
    rMergeSort(array, 0, n-1);
}

void rMergeSort(int * array, int left, int right){
    if(left < right) {
        int m = (left + right) / 2;
        rMergeSort(array, left, m);
        rMergeSort(array, m + 1, right);
        merge(array, left, m, right);
    }
    return;
}

void merge(int * array, int left, int mid, int right){
    int bArray[n];

    int i = left;
    int k = left;
    int j = mid + 1;

    while(i <= mid && j <= right){
        if(array[i] <= array[j]){
            bArray[k++] = array[i++];
        }else{
            bArray[k++] = array[j++];
        }
    }

    while(i <= mid){
        bArray[k++] = array[i++];
    }

    while(j <= right){
        bArray[k++] = array[j++];
    }

    for(int k1 = left; k1<=right; k1++){
        array[k1] = bArray[k1];
    }
    return;
}

void printArray(int * array){
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
}