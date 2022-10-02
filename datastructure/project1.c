#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// 중복이 있을 수 있는 n개 정수 원소들로 이루어진 L 원소 가운데 k 번째 작은 원소를 찾아 반환한다.
int findKthSmallest(int L[], int n, int k);

// 리스트는 1D 배열 또는 단일 연결리스트
int * buildList(int n, int minValue, int maxValue);

// buildList(10, 1, 100)을 호출해 1과 100 사이의 정수 10개로 이루어진 리스트 만들어 L에 저장
void writeList(int *L, int n);

// 다운 힙
void downHeap(int H[], int idx, int n);

// 재귀적 힙 생성
void rBuildHeap(int * L, int i, int n);

// 제자리 힙정렬
void inPlaceHeapSort(int L[], int n);

// 메인 함수
int main(){

    int *L;

    int * output = (int *) malloc(sizeof(int) * 3);

    clock_t start, finish;

    int e;

    double t;

    // 조건 1. L ← buildList(10, 1, 100)
    L = buildList(10, 1, 100);

    // 조건 2. 2. writeList(L)
    writeList(L, 10);

    // 조건 3. 3. for k ← 1 to 3
    //output[k] ← findKthSmallest(L, 10, k)
    for(int k=1; k<4; k++) {
       output[k-1] = findKthSmallest(L, 10, k);
    }

    // 조건 4. 4. write(output[1], output[2], output[3])
    printf("%d %d %d\n", output[0], output[1], output[2]);

    free(L);
    free(output);

    // 조건 5. 5. L ← buildList(100000, 1, 1000000)
    L = buildList(100000, 1, 1000000);

    // 조건 6. 6. karray ← {1, 100, 99900, 99999}
    int karray[4] = {1, 100, 99900, 99999};

    // 조건 7. 7. for k ← 0 to 3
    // -1부터 한 이유는 메모리 생성 문제로 정확한 시간 측정이 안됨

    for (int k = -1; k <= 3; k++) {

        start = clock(); // 시작 시간
        e = findKthSmallest(L, 100000, karray[k]);
        finish = clock(); // 종료 시간

        // 정확한 시간 측정을 위한 코드
        if(k == -1){
            continue;
        }

        t = (double)(finish-start)/CLOCKS_PER_SEC;%

        printf("%d %lf\n", e, t);

    }

    free(L);

    return 0;

}

int * buildList(int n, int minValue, int maxValue){

    int * p = (int *) malloc(sizeof(int) * (n + 1));

    srand(time(NULL));

    for(int i=1; i<=n; i++){
        p[i] = (rand() % (maxValue + 1 - minValue)) + minValue;
    }

    return p;

}

void writeList(int *L, int n){

    for(int i=1; i<=n; i++){
        printf("%d ", L[i]);
    }

    printf("\n");

}

int findKthSmallest(int L[], int n, int k){
    inPlaceHeapSort(L, n);
    int index = 0;

    for(int i=0; i<n; i++){
        if(i == k){
            index = i;
        }
    }
    return L[index];
}

void rBuildHeap(int * L, int i, int n) {

    if (i > n){
        return;
    }

    rBuildHeap(L, i * 2, n);
    rBuildHeap(L, i * 2 + 1, n);
    downHeap(L, i, n);

}

void inPlaceHeapSort(int L[], int n) {

    rBuildHeap(L, 1, n);

    for (int i = n; i > 1; i--) {
        int tmp = L[1];
        L[1] = L[i];
        L[i] = tmp;
        downHeap(L,1,i - 1);
    }

}


void downHeap(int H[], int idx, int n) {

    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left > n) {
        return;
    }

    int biggerIdx = left;

    if (right <= n) {
        if (H[right] > H[biggerIdx]) {
            biggerIdx = right;
        }
    }

    if (H[idx] >= H[biggerIdx]) {
        return;
    }

    //swap
    int temp = H[biggerIdx];
    H[biggerIdx] = H[idx];
    H[idx] = temp;

    downHeap(H, biggerIdx, n);
}
