#include <stdio.h>

int power(int m) {
    int res = 1;
    for (int i = 0; i < m; i++) {
        res *= 2;
    }
    return res;
}

int toggle(int num, int k) {
    return (num ^ (1 << (k - 1)));
}

int main() {
    int n;
    int len;
    int m;
    scanf("%d %d", &n, &m);

    len = power(n);

    int cnt = 0;
    int num;
    for (int i = 1; i < len; i++) {
        if (i % m != 0) {
            for (int j = 1; j <= n; j++) {
                num = toggle(i, j);
                if (num % m == 0 && num != 0) {
                    cnt++;
                    break;
                }
            }
        }
    }

    printf("%d", cnt);
    return 0;
}