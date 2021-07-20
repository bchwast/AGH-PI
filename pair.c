#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main () {
    char trash;
    unsigned int n;
    int k;
    int* array;
    int pairs = 0;

    scanf("%d %d", &n, &k);
    array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d%c", &array[i], &trash);
    }

    qsort(array, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        int pair = 0;
        for (int j = 0; j < n; j++) {
            if (array[i] != array[j]) {
                if ((array[j] >= array[i] - k) && (array[j] <= array[i] + k)) {
                    pair = 1;
                    pairs++;
                    break;
                }
            }
        }
        while ( i + 1 < n && array[i + 1] == array[i]) {
            pairs += pair;
            i++;
        }
    }

    printf("%d", pairs);
    return 0;
}