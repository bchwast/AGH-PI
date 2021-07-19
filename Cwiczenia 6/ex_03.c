#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, t, mono = 0;
    unsigned int points, red_lines, triangles_size;
    scanf("%d %d", &points, &red_lines);
    m = (int) red_lines;
    n = (int) points;
    triangles_size = (points * (points - 1) * (points - 2)) / 6;
    t = (int) triangles_size;

    int **lines = (int **) malloc(red_lines * sizeof(int *));
    for (int i = 0; i < m; i++) {
        lines[i] = (int *) malloc(2 * sizeof(int));
    }

    int **triangles = (int **) malloc(triangles_size * sizeof(int *));
    for (int i = 0; i < t; i++) {
        triangles[i] = (int *) malloc(4 * sizeof(int));
    }

    int ind = 0;
    for (int i = 1; i <= (n - 2); i++) {
        for (int j = i + 1; j <= (n - 1); j++) {
            for (int k = j + 1; k <= n; k++) {
                triangles[ind][0] = i;
                triangles[ind][1] = j;
                triangles[ind][2] = k;
                triangles[ind][3] = 0;
                ind++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &lines[i][0], &lines[i][1]);
    }

    for (int i = 0; i < m; i++) {
        int l = lines[i][0], r = lines[i][1];
        for (int j = 0; j < t; j++) {
            if ((triangles[j][0] == l && triangles[j][1] == r) || (triangles[j][0] == l && triangles[j][2] == r) ||
                    (triangles[j][1] == l && triangles[j][2] == r)) {
                triangles[j][3]++;
            }
        }
    }

    for (int i = 0; i < t; i++) {
        if (triangles[i][3] == 0 || triangles[i][3] == 3) {
            mono++;
        }
    }

    printf("%d", mono);

    for (int i = 0; i < m; i++) {
        free(lines[i]);
    }
    free(lines);
    for (int i = 0; i < t; i++) {
        free(triangles[i]);
    }
    free(triangles);

    return 0;
}