#include <stdio.h>

int prime(int num) {
    if (num == 2 || num == 3) return 1;
    if (num <= 1 || num % 2 == 0 || num % 3 == 0) return 0;

    int a = 5;
    while (a * a <= num) {
        if (num % a == 0) return 0;
        a += 2;
        if (num % a == 0) return 0;
        a += 4;
    }

    return 1;
}

int main () {
    int l, u, k, copy;

    scanf("%d %d %d", &l, &u, &k);

    for (int i = l; i <= u; i++) {
        if (prime(i)) {
            int result = 0;
            copy = i;

            while ((result != 1) && (result != 4)) {
                result = 0;
                while (copy > 0) {
                    result += (copy % 10) * (copy % 10);
                    copy /= 10;
                }
                copy = result;
            }
            if (result == 1) {
                k--;
            }

            if (k == 0) {
                printf("%d", i);
                return 0;
            }
        }
    }

    printf("-1");
    return 1;
}