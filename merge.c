#include <stdio.h>
#include <stdlib.h>


int main () {
    unsigned int n;

    scanf("%d", &n);

    int **t1 = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        t1[i] = (int *)malloc(n * sizeof(int));
    }

    int *t2 = (int *)malloc((n * n) * sizeof(int));
    int *begs = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char trash;
            scanf("%d%c", &t1[i][j], &trash);
        }
    }

    int ind = 0;
    for (int swipe = 0; swipe < (n * n); swipe++){
        int f = 0;

        while (begs[f] >= n) {
            f++;
        }

        int min = t1[f][begs[f]];
        int row = f;

        for (int i = 0; i < n; i++) {
            if (begs[i] < n) {
                if (t1[i][begs[i]] < min) {
                    min = t1[i][begs[i]];
                    row = i;
                }
            }
        }

        if (ind > 0) {
            if (min != t2[ind - 1]) {
                t2[ind] = min;
                ind++;
            }
        }
        if (ind == 0) {
            t2[ind] = min;
            ind++;
        }

        begs[row]++;
    }

    for (int i = 0; i < ind; i++) {
        printf("%d ", t2[i]);
    }

    free(t1);
    free(t2);
    free(begs);

    return 0;
}