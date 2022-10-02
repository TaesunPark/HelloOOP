#pragma warning(disable:4996)
#include<stdio.h>

void downHeap(int idx);
void printHeap();
void rBuildHeap(int i);

int n;
int H[100];

// 최대 힙
int main() {

    char m;
    int key;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }
    rBuildHeap(1);
    printHeap();
    return 0;
}


void rBuildHeap(int i) {

    if (i > n) {
        return;
    }

    rBuildHeap(2 * i);
    rBuildHeap(2 * i + 1);
    downHeap(i);
    return;
}

void printHeap() {
    for (int i = 1; i < n + 1; i++)
        printf(" %d", H[i]);
    printf("\n");
}

void downHeap(int idx) {

    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left > n && right > n)
        return;

    int biggerIdx = left;

    if (right <= n) {
        //left,right 뭐가 더 큰지
        if (H[right] > H[biggerIdx])
            biggerIdx = right;
    }

    if (H[idx] >= H[biggerIdx])
        return;

    int temp = H[biggerIdx];
    H[biggerIdx] = H[idx];
    H[idx] = temp;

    downHeap(biggerIdx);
}
