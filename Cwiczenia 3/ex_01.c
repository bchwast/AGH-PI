#include <stdio.h>
#include <stdlib.h>


int main() {
    char trash;
    unsigned int n;
    int k;
    int sum = 0;
    int* array;

    scanf("%d %d", &n, &k);
    array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d%c", &array[i], &trash);
    }

    for (int op = 1; op <= k; op++) {
        int lrgst = 0;

        for (int i = 0; i < n; i++) {
            if (array[i] >= array[lrgst]) {
                lrgst = i;
            }
        }

        array[lrgst] /= 2;
    }

    for (int i = 0; i < n; i++) {
        sum += array[i];
    }

    printf("%d", sum);
}