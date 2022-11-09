//
// Created by taesunpark on 2022/10/06.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void inPlaceQuickSort(int * L, int l, int r);
int inPlacePartition(int * L, int l, int r, int k);
int findPivot(int l, int r);


int main(){
    int n;
    int * p;

    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    inPlaceQuickSort(p, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d ", p[i]);
    }

    free(p);
}

void inPlaceQuickSort(int * L, int l, int r){
    if(l >= r){
        return;
    }

    int k = findPivot(l, r);
    int pivot = inPlacePartition(L, l, r, k);
    inPlaceQuickSort(L, l, pivot - 1);
    inPlaceQuickSort(L, pivot + 1, r);
}

int inPlacePartition(int * L, int l, int r, int k){
    int p = L[k];

    int tmp = L[k];
    L[k] = L[r];
    L[r] = tmp;

    int i = l;
    int j = r - 1;

    while (i <= j) {

        while (i <= j && L[i] <= p) {
            i = i + 1;
        }
        while (i <= j && L[j] >= p) {
            j = j - 1;
        }

        if (i < j) {
            int tmp2 = L[i];
            L[i] = L[j];
            L[j] = tmp2;
        }
    }

    int tmp3 = L[i];
    L[i] = L[r];
    L[r] = tmp3;

    return i;
}

int findPivot(int l, int r){
    return ((rand() % (r - l + 1)) + l);
}
