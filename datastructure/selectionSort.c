#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void selectSort(int *arr, int n);
int dump;

int main() {
    // 무순 리스트, 선택 정렬
    int n; // 입력 값
    int *arr;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int)*n);
    memset(arr, 0, (n) * sizeof (int));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    selectSort(arr, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

}

void selectSort(int *arr, int n){
    for(int i=n-1; i>0; i--){
        int tmp = i;
        for(int j=i-1; j>=0; j--){
            if(arr[tmp] < arr[j]){
                tmp = j;
            }
        }
        dump = arr[i];
        arr[i] = arr[tmp];
        arr[tmp] = dump;
    }
}