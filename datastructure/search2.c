//
// Created by taesunpark on 2022/10/13.
//

#include <stdio.h>
#include<stdlib.h>
#include<memory.h>

int* arr, n;
int findElement(int k);

int main() {

    int k;

    scanf("%d %d", &n, &k);

    arr = (int*)malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf(" %d", findElement(k));
}

int findElement(int k) {

    int left, right, mid;
    left = 0;
    right = n - 1;

    while (1) {

        if (left > right) {

            if (k >= 0 && arr[right] <= k) {

                if (left == n) {
                    return n;
                }

                return left;
            }
            else if (k <= 0 && arr[left] >= k) {
                return left;
            }

            break;
        }

        mid = (left + right) / 2;

        if (k == arr[mid]) {
            return mid;
        }

        else if (k < arr[mid]) {
            right = mid - 1;
        }

        else if (k > arr[mid]) {
            left = mid + 1;
        }
    }
}
