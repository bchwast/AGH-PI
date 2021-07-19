#include <stdio.h>
#define MAX 100

int scale (int array[MAX], int target, int index, int sup) {
    if (index > sup) {
        return 0;
    }
    if (target == 0) {
        return 1;
    }
    return scale(array, target - array[index], index + 1, sup) || scale(array, target, index + 1, sup) ||
    scale(array, target + array[index], index + 1, sup);
}


int main () {
    int weights[MAX], n, w;
    int ind = 0;
    int sum = 0;
    char temp;
    scanf("%d %d", &n, &w);

    while (temp != '\n') {
        scanf("%d%c", &weights[ind], &temp);
        ind++;
    }

    for (int i = 0; i < n; i++) {
        sum += weights[i];
    }

    if (sum < w) {
        printf("NO");
        return 0;
    }

    if (scale(weights, w, 0, n) == 1) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}