#include <stdio.h>


long long square(long long num) {
    return num * num;
}

long long sum(long long num) {
    if (num == 0) {
        return 0;
    }
    if (num % 2 == 1) {
        return square((num + 1) / 2) + sum(num / 2);
    }
    else {
        return square(num / 2) + sum(num / 2);
    }
}

int main() {
    long long n;

    scanf("%lld", &n);

    printf("%lld", sum(n));
    return 0;
}
