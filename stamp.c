#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    unsigned int sq, rec1, rec2;
    int n, k, l, res = 0;
    scanf("%d %d %d", &sq, &rec1, &rec2);
    n = (int) sq;
    k = (int) rec1;
    l = (int) rec2;

    int **T = (int **) malloc(sq * sizeof(int *));
    for (int i = 0; i < n; i++) {
        T[i] = (int *) malloc(sq * sizeof(int));
    }
    int **P = (int **) malloc(rec1 * sizeof(int *));
    for (int i = 0; i < k; i++) {
        P[i] = (int *) malloc(rec2 * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char trash;
            scanf("%d%c", &T[i][j], &trash);
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            char trash;
            scanf("%d%c", &P[i][j], &trash);
        }
    }

    for (int i = 0; i < n - k; i++) {
        for (int j = 0; j < n - l; j++) {
            int curr = 0;
            for (int a = 0; a < k; a++) {
                for (int b = 0; b < l; b++) {
                    if (P[a][b] == 1) {
                        curr += T[i + a][j + b];
                    }
                }
            }
            res = max(res, curr);
        }
    }

    for (int i = 0; i < n; i++) {
        free(T[i]);
    }
    free(T);
    for (int i = 0; i < k; i++) {
        free(P[i]);
    }
    free(P);

    printf("%d", res);
    return 0;
}