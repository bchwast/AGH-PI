#include <stdio.h>
#include <stdlib.h>

int main() {
    int k, ammount = 0;
    unsigned int array_size;
    scanf("%d %d", &array_size, &k);
    int n = (int) array_size;


    int **T = (int **)malloc(array_size * sizeof(int *));
    int **results = (int **)malloc((array_size * array_size) * sizeof(int *));
    for (int i = 0; i < n; i++) {
        T[i] = (int *)malloc(array_size * sizeof(int));
    }
    for (int i = 0; i < n * n; i++) {
        results[i] = (int *)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char trash;
            scanf("%d%c", &T[i][j], &trash);
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            for (int a = 1; a < n; a++) {
                if ((i - a < 0) || (j - a < 0) || (i + a >= n) || (j + a) >= n) {
                    break;
                }
                int sum = 0;
                for (int y = (i - a) + 1; y < i + a; y++) {
                    sum += T[y][j - a];
                    sum += T[y][j + a];
                }
                for (int x = j - a; x <= j + a; x++) {
                    sum += T[i - a][x];
                    sum += T[i + a][x];
                }

                if (sum == k) {
                    results[ammount][0] = i;
                    results[ammount][1] = j;
                    ammount++;
                }
            }
        }
    }

    printf("%d\n", ammount);
    for (int i = 0; i < ammount; i++) {
        printf("%d %d\n", results[i][0], results[i][1]);
    }

    for (int i = 0; i < n; i++) {
        free(T[i]);
    }
    free(T);

    for (int i = 0; i < n * n; i++) {
        free(results[i]);
    }
    free(results);

    return 0;
}