//
// Created by taesunpark on 2022/09/22.
//
#pragma warning(disable:4996)
#include<stdio.h>

void printHeap();
void buildHeap(int * li);
void downHeap(int idx, int last);
void inPlaceHeapSort();
void insertItem(int k);
void upHeap(int idx);
int removeMax();

int n, m;
int H[100], L[100];

int main() {
    m=0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &L[i]);
    }

    inPlaceHeapSort();
    printHeap();
    return 0;
}


void printHeap() {

    for (int i = 1; i < n + 1; i++) {
        printf(" %d", H[i]);
    }

    printf("\n");
}

void inPlaceHeapSort() {

    buildHeap(L);

    for (int i = m; i >= 1; i--) {
        int tmp = H[1];
        H[1] = H[i];
        H[i] = tmp;
        downHeap(1, i - 1);
    }

}

void downHeap(int idx, int last) {

    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left > last) {
        return;
    }

    int greater = left;

    if (right <= last) {
        if (H[right] > H[greater])
            greater = right;
    }

    if (H[idx] >= H[greater])
        return;

    int temp = H[greater];
    H[greater] = H[idx];
    H[idx] = temp;

    downHeap(greater, last);
}

void buildHeap(int * li){

    for(int i = 1; i <= n; i++){
        insertItem(li[i]);
    }
}

void insertItem(int k){
    m = m + 1;
    H[m] = k;
    upHeap(m);
    return;
}

void upHeap(int idx){
    if(idx == 1){
        return;
    }

    if(H[idx] <= H[idx/2]){
        return;
    }

    int temp = H[idx];
    H[idx] = H[idx/2];
    H[idx/2] = temp;
    upHeap(idx/2);
}

int removeMax(int i){
    int key = H[1];
    H[1] = H[m];
    m = m-1;
    downHeap(1, i);
    return key;
}