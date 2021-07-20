#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    unsigned int array_size;
    int m_area = 0;
    scanf("%d", &array_size);
    int n = (int) array_size;

    int **array = (int **)malloc(array_size * sizeof(int *));
    for (int i = 0; i < array_size; i++) {
        array[i] = (int *) malloc(array_size * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char trash;
            scanf("%d%c", &array[i][j], &trash);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            int area, curr_max = 0, height = n;
            for (int x = j; x < n; x++) {
                if (array[i][x] == 1) {
                    break;
                }

                for (int y = i; y <= n; y++) {
                    if ((y == n) || (array[y][x] == 1)) {
                        height = min(height, y - i);
                        break;
                    }
                }
                area = height * (x - j + 1);
                curr_max = max(area, curr_max);
            }
            m_area = max(m_area, curr_max);
        }
    }

    printf("%d", m_area);

    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
