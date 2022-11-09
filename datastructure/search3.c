//
// Created by taesunpark on 2022/10/13.
//

#include <stdio.h>

int findElement(int a, int b, int n, char str[100]) {

    int mid;
    int i = 0;

    while (1) {

        if (a >= b) {
            return a;
        }

        mid = (a + b) / 2;

        if (str[i] == 'N') {
            b = mid;
        }
        else if (str[i] == 'Y') {
            a = mid + 1;
        }
        i++;
    }
}


int main() {

    int a, b, n;
    char str[100];

    scanf("%d %d %d", &a, &b, &n);

    scanf("%s", str);

    printf(" %d", findElement(a, b, n, str));

    return 0;
}