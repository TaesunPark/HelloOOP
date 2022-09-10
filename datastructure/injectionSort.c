#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include<memory.h>

// 오름 차순 정렬
int main() {

    int n, * arr, tmp;

    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    memset(arr, 0, (n) * sizeof (int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {

        int tmp = arr[i];
        int j = i - 1;

        while ((j >= 0) && (arr[j] >= tmp)) {
            //한칸씩 뒤로 밀기.
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;

    }

    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    free(arr);
    return 0;
}
