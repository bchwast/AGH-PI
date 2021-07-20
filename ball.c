#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    int n;
    scanf("%d", &n);

    int **colours = (int **) malloc(3 * sizeof(int *));
    for (int c = 0; c < 3; c++) {
        colours[c] = (int *) malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            char trash;
            scanf("%d%c", &colours[c][i], &trash);
        }
    }
    if (n < 3) {
        printf("-1");
        return 0;
    }

    int min_sum = 2147483647;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) {
                    continue;
                }
                int sum = 0;
                for (int a = 0; a < n; a++) {
                    if (a != i) {
                        sum += colours[0][a];
                    }
                    if (a != j) {
                        sum += colours[1][a];
                    }
                    if (a != k) {
                        sum += colours[2][a];
                    }
                    if (a != i && a != j && a != k) {
                        sum -= max3(colours[0][a], colours[1][a], colours[2][a]);
                    }
                }
                if (sum < min_sum) {
                    min_sum = sum;
                }
            }
        }
    }

    printf("%d", min_sum);

    return 0;
}