//
// Created by taesunpark on 2022/10/13.
//
#include <stdio.h>
#include<stdlib.h>
#include <memory.h>

int* arr, n;
int findElement(int k);
int rFindElement(int k, int left, int right);

int main() {

	int k;

	scanf("%d %d", &n, &k);

	arr = (int *) malloc(sizeof(int) * n);
    memset(arr, 0, n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf(" %d", findElement(k));
    free(arr);
}

int findElement(int k) {
	return rFindElement(k, 0, n - 1);
}

int rFindElement(int k, int left, int right) {

	int mid;

	if (left > right) {

		if (arr[right] <= k && k >= 0) {
            return right;
        } else if (arr[left] >= k && k < 0) {

			if (left == 0) {
                return -1;
            }

			return left;
		}

		return -1;
	}

	mid = (left + right) / 2;

	if (k == arr[mid]) {
        return mid;
    }
	else if (k < arr[mid]) {
        return rFindElement(k, left, mid - 1);
    }
	else if (k > arr[mid]) {
        return rFindElement(k, mid + 1, right);
    }
}