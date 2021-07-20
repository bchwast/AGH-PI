#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    unsigned array_size;
    int n, k, res = 0;
    scanf("%d %d", &array_size, &k);
    n = (int) array_size;
    array_size *= 3;

    int **T = (int **) malloc(array_size * sizeof(int *));
    for (int i = 0; i < n * 3; i++) {
        T[i] = (int *) malloc(array_size * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char trash;
            scanf("%d%c", &T[i][j], &trash);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j + n] = T[i][j];
            T[i][j + (2 * n)] = T[i][j];
            T[i + n][j] = T[i][j];
            T[i + n][j + n] = T[i][j];
            T[i + n][j + (2 * n)] = T[i][j];
            T[i + (2 * n)][j] = T[i][j];
            T[i + (2 * n)][j + n] = T[i][j];
            T[i + (2 * n)][j + (2 * n)] = T[i][j];
        }
    }

    for (int i = n; i < 2 * n; i++) {
        for (int j = n; j < 2 * n; j++) {
            int l1 = T[i][j], l2 = T[i][j], l3 = T[i][j], l4 = T[i][j], l5 = T[i][j], l6 = T[i][j], l7 = T[i][j], l8 = T[i][j];

            for (int l = 1; l < k; l++) {
                l1 += T[i - l][j];
                l2 += T[i - l][j + l];
                l3 += T[i][j + l];
                l4 += T[i + l][j + l];
                l5 += T[i + l][j];
                l6 += T[i + l][j - l];
                l7 += T[i][j - l];
                l8 += T[i - l][j - l];
            }
            res = max(max(max(max(max(max(max(max(res, l1), l2), l3), l4), l5), l6), l7), l8);
        }
    }

    printf("%d", res);

    for (int i = 0; i < 3 * n; i++) {
        free(T[i]);
    }
    free(T);
    return 0;
}