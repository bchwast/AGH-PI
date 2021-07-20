#include <stdio.h>
#define MAX 158

int factorial[MAX];

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < MAX - 1; i++) {
        factorial[i] = 0;
    }
    factorial[MAX - 1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = MAX - 1; j >= 0; j--) {
            factorial[j] *= i;
            }

        int ind = MAX - 1;
        while (ind > 0) {
            if (factorial[ind] >= 10) {
                factorial[ind - 1] += (factorial[ind] / 10);
                factorial[ind] %= 10;
            }
            else {
                ind--;
            }
        }
    }

    int beg = 0;
    while (factorial[beg] == 0) {
        beg++;
    }

    for (int i = beg; i < MAX; i++) {
        printf("%d", factorial[i]);
    }

    return 0;
}