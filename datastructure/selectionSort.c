//
// Created by taesunpark on 2022/09/08.
//
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include<memory.h>

int findPosition(int* arr, int en, int n);

int main(){
    int n;
    int * arr = NULL;
    scanf("%d", &n);
    arr = (int *) malloc(sizeof(int)*(n+1));
    // 메모리 초기화
    memset(arr, 0, (n+1) * sizeof (int));

    // 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    arr[n] = 0;

    // 선택 정렬
    for (int i = 0; i < n; i++) {
        int index;
        index = findPosition(arr, n-i, n);
        arr[n] = arr[n-i-1];
        arr[n-i-1] = arr[index];
        arr[index] = arr[n];
        arr[n] = 0;
    }

    for (int j = 0; j < n; ++j) {
        printf("%d ", arr[j]);
    }

    free(arr);
    return 0;
}

int findPosition(int* arr, int en, int n){
    int position = 0;

    for (int i = 0; i < en; i++) {
        if (arr[i] > arr[n]){
            position = i;
            arr[n] = arr[i];
        }
    }

    return position;
}


