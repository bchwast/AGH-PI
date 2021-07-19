#include <stdio.h>
#include <stdlib.h>


long long cyc(long long a, long long b) {
    if (a < 0) {
        return a + b;
    }
    else if (a >= b) {
        return a - b;
    }
    else {
        return a;
    }
}

long long sqr(long long a) {
    return a * a;
}

long long det(long long x_a, long long y_a, long long x_b, long long y_b, long long x_c, long long y_c) {
    return (x_b - x_a) * (y_c - y_a) - (y_b - y_a) * (x_c - x_a);
}

long long min(long long a, long long b) {
    if (a < b) {
        return a;
    }
    return b;
}

long long max(long long a, long long b) {
    if (a < b) {
        return b;
    }
    return a;
}

int main() {
    int t, t_;
    scanf("%d", &t);
    t_ = t;
    long long *res_ = (long long *) malloc(t * sizeof(long long));

    while (t > 0) {
        t--;
        long long n;
        scanf("%lld", &n);
        long long *x = (long long *) malloc(2 * n * sizeof(long long));
        long long *y = (long long *) malloc(2 * n * sizeof(long long));
        long long *rep = (long long *) malloc(4 * n * sizeof(long long));
        long long *rad = (long long *) malloc(8 * n * sizeof(long long));
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &x[2 * i], &y[2 * i]);
            x[2 * i] *= 2;
            y[2 * i] *= 2;
        }
        for (int i = 0; i < n; i++) {
            x[2 * i + 1] = (x[2 * i] + x[cyc(2 * i + 2, 2 * n)]) / 2;
            y[2 * i + 1] = (y[2 * i] + y[cyc(2 * i + 2, 2 * n)]) / 2;
        }

        for (int i = 0; i < 2 * n; i++) {
            rep[2 * i] = sqr(x[i] - x[cyc(i - 1, 2 * n)]) + sqr(y[i] - y[cyc(i - 1, 2 * n)]);
            rep[2 * i + 1] = 2 * det(x[i], y[i], x[cyc(i - 1, 2 * n)], y[cyc(i - 1, 2 * n)], x[cyc(i + 1, 2 * n)], y[cyc(i + 1, 2 * n)]);
            long long tmp_x = y[cyc(i - 1, 2 * n)] - y[i] + x[i];
            long long tmp_y = -1 * x[cyc(i - 1, 2 * n)] + x[i] + y[i];
            if (det(x[i], y[i], tmp_x, tmp_y, x[cyc(i + 1, 2 * n)], y[cyc(i + 1, 2 * n)]) < 0) {
                rep[2 * i + 1]++;
            }
        }
        long long i = 1;
        long long j = 0;
        while (i < 8 * n) {
            while ((i + j + 1 < 8 * n) && (i - j > 0) && (rep[cyc(i - j - 1, 4 * n)] == rep[cyc(i + j + 1, 4 * n)])) {
                j++;
            }
            rad[i] = j;
            long long k = 1;
            while ((k <= j) && (rad[i - k] != j - k)) {
                rad[i + k] = min(rad[i - k], j - k);
                k++;
            }
            j = max(0, j - k);
            i += k;
        }
        long long res = 0;
        for (int ind = 0; ind < 2 * n; ind++) {
            if (rad[2 * ind + 1 + 2 * n] >= 2 * n) {
                res++;
            }
        }
        res_[t] = res / 2;
        free(x);
        free(y);
        free(rep);
        free(rad);
    }

    for (int i = t_ - 1; i >= 0; i--) {
        printf("%lld\n", res_[i]);
    }
    free(res_);
    return 0;
}