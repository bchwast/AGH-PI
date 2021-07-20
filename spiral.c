#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int array_size;
    int num = 0, border = 0;
    scanf("%d", &array_size);
    int n = (int) array_size;

    int **T = (int **)malloc(array_size * sizeof(int *));
    for (int i = 0; i < array_size; i++) {
        T[i] = (int *)malloc(array_size * sizeof(int));
    }

    while (num < n * n) {
        for (int i = border; i < n - border; i++) {
            num++;
            T[border][i] = num;
        }

        for (int i = border + 1; i <= n - (border + 1); i++) {
            num++;
            T[i][(n - 1) - border] = num;
        }

        for (int i = (n - 2) - border; i >= border; i--) {
            num++;
            T[(n - 1) - border][i] = num;
        }

        for (int i = (n - 1) - (border + 1); i > border; i--) {
            num++;
            T[i][border] = num;
        }

        border++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(T[i]);
    }
    free(T);

    return 0;
}