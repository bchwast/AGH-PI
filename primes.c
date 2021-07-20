#include <stdio.h>

int is_prime(int num) {
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num <= 1 || num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

    int a = 5;
    while (a * a <= num) {
        if (num % a == 0) {
            return 0;
        }
        a += 2;
        if (num % a == 0) {
            return 0;
        }
        a += 4;
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        if (is_prime(i) == 1) {
            int copy = i;
            int prev = i;
            while (copy > 0 && copy % 10 <= prev) {
                prev = copy % 10;
                copy /= 10;
            }
            if (copy == 0) {
                printf("%d\n", i);
            }
        }
    }
}