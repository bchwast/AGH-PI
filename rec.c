#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

int plane[SIZE][SIZE];

int main() {
    unsigned int array_size;
    scanf("%d", &array_size);
    int n = (int) array_size, cnt = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            plane[i][j] = 0;
        }
    }

    int **rectangles = (int **) malloc(array_size * sizeof(int *));
    for (int i = 0; i < n; i++) {
        rectangles[i] = (int *) malloc(4 * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            char trash;
            scanf("%d%c", &rectangles[i][j], &trash);
        }
    }

    for (int rect = 0; rect < n; rect++) {
        for (int i = rectangles[rect][0] + 100; i < rectangles[rect][2] + 100; i++) {
            for (int j = rectangles[rect][1] + 100; j < rectangles[rect][3] + 100; j++) {
                if (plane[i][j] == 0) {
                    plane[i][j] = 1;
                }
                else {
                    plane[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (plane[i][j] == 1) {
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    for (int i = 0; i < n; i++) {
        free(rectangles[i]);
    }
    free(rectangles);

    return 0;
}