#include <stdio.h>
#define MAX 1000

int main() {
    int array[MAX], n;
    int i = 0;
    char temp;

    scanf("%d", &n);

    while (temp != '\n') {
        scanf("%d%c", &array[i], &temp);
        i++;
    }

    int left, right;

    for (int a = 0; a < n; a++) {
        left = 0;
        right = 0;
        for (int b = 0; b < a; b++) {
            left += array[b];
        }
        for (int b = n - 1; b > a; b--) {
            right += array[b];
        }

        if (left == right) {
            printf("%d", a);
            return 0;
        }
    }
    return 0;
}
