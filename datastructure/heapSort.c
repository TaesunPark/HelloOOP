#include <stdio.h>

int H[100];
int L[100];

int n;
void insertItem(int k);
void upHeap(int v);
int isEmpty(int L[]);
int isSize();

int main(){

    scanf("%d", &n);

    for(int i=1; i<n; i++){
        scanf("%d", &H[i]);
        insertItem(&H[i]);
    }

    while()

}

int isEmpty(int L[]){
    for(int i=0; i<100;)
}

void insertItem(int k){
    n = n + 1;
    H[n] = k;
    upHeap(k);
    return;
}

void upHeap(int v){
    if(v == 1){
        return;
    }
    if(H[v] <= H[v/2]){
        return;
    }
    // 교체
    int tmp = H[v];
    H[v] = H[v / 2];
    H[v / 2] = tmp;

    upHeap(v / 2);
}
