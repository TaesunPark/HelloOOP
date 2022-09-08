//
// Created by taesunpark on 2022/09/08.
//
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include<memory.h>

int main(){
    int n;
    int *arr = NULL;
    scanf("%d", &n);
    arr = (int *) malloc(sizeof(int)*(n+1));
    // 메모리 초기화
    memset(arr, 0, (n+1) * sizeof (int));

    // 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    arr[n] = 0;


    return 0;
}