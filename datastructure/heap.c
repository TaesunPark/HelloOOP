//
// Created by taesunpark on 2022/09/15.
//
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n; // 힙의 크기

void insertItem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();
void swap();

int main(){
    char cmd;
    int item;
    int checkedNum=0;
    
    while (checkedNum != 1){
        scanf("%c", &cmd);

        switch (cmd) {
            case 'i':
                getchar();
                scanf("%d", &item);
                insertItem(item);
                printf("0\n");
                break;
            case 'd':
                printf("%d\n", removeMax());
                break;
            case 'p':
                printHeap();
                break;
            case 'q':
                checkedNum = 1;
                break;
            default:
                break;
        }
    }
}

void insertItem(int key){
    n = n + 1;
    H[n] = key;
    upHeap(n);
    return;
}

int removeMax(){
    int key = H[1];
    H[1] = H[n];
    n = n-1;
    downHeap(1);
    return key;
}

void upHeap(int i) {
    // 루트면
    if (i == 1)
        return;
    // 부모가 더 크면
    if (H[i / 2] >= H[i])
        return;

    // 교체
    int tmp = H[i];
    H[i] = H[i / 2];
    H[i / 2] = tmp;

    upHeap(i / 2);
}

void downHeap(int i){
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left > n) return;

    // left child
    int maxIdx = left;

    if (right <= n) {
        if (H[right] > H[maxIdx])
        {
            maxIdx = right;
        }
    }

    if (H[i] >= H[maxIdx]) return;

    swap(maxIdx, i);

    downHeap(maxIdx);

}

void swap(int value1, int value2){
    int tmp = H[value1];
    H[value1] = H[value2];
    H[value2] = tmp;
}

void printHeap() {
    for (int i = 1; i <= n ; i++){
        printf(" %d", H[i]);
    }
    printf("\n");
}

