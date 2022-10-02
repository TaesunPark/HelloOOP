#include<stdio.h>
#include<stdlib.h>

int H[100];
int n=0;

void insertItem(int value);
void upHeap(int idx);
int removeMax();
void downHeap(int idx);
void printHeap();

int main(){
    char ch;
    int value;
    int check = 0;

    while(check == 0){
        scanf("%c", &ch);

        switch(ch){
            case 'i':
                getchar();
                scanf("%d", &value);
                insertItem(value);
                printf("0\n");
                break;
            case 'd':
                printf("%d", removeMax());
                break;
            case 'p':
                printHeap();
                break;
            case 'q':
                check = 1;
                break;
        }
    }
    return 0;
}

int removeMax(){
    int key = H[1];
    H[1] = H[n];
    n = n-1;
    downHeap(1);
    return key;
}

void insertItem(int value){
    n = n+1;
    H[n] = value;
    upHeap(n);
    return;
}

void upHeap(int idx){

    if(idx == 1){
        return;
    }

    if(H[idx / 2] > H[idx]){
        return;
    }

    int tmp = H[idx];
    H[idx] = H[idx/2];
    H[idx/2] = tmp;

    upHeap(idx/2);
}

void downHeap(int idx){
    int leftIdx = idx * 2;
    int rightIdx = (idx * 2) + 1;

    if(leftIdx > n){
        return;
    }

    int biggerIdx = leftIdx;

    if (H[biggerIdx] < H[rightIdx]){
        biggerIdx = rightIdx;
    }
    if(H[idx] >= H[biggerIdx]){
        return;
    }

    int tmp = H[idx];
    H[idx] = H[biggerIdx];
    H[biggerIdx] = tmp;

    downHeap(biggerIdx);
}

void printHeap(){
    for(int i=1; i<=n; i++){
        printf("%d ",H[i]);
    }
    printf("\n");
}