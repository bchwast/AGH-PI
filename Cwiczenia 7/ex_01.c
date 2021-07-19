#include <stdio.h>
#include <stdlib.h>
#define SIZE1 65
#define MAX 100000

long dp[SIZE1];
int nums[MAX][SIZE1 - 1];

long min(long a, long b) {
    if (a < b) return a;
    return b;
}

long power(int num) {
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 3;
    for (int i = 3; i <= 64; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] > MAX) {
            dp[i] = MAX;
        }
    }
    return dp[num];
}

void write(long beg, long amm, int ind, int n, int wall) {
    for (long i = beg; i < min(beg + dp[n - 1], MAX); i++) {
        nums[i][ind] = 0;
    }
    for (long i = min(beg + dp[n - 1], MAX); i < amm; i++) {
        nums[i][ind] = 1;
    }

    if (ind + 1 < wall) {
        write(beg, min(beg + dp[n - 1], MAX), ind + 1, n - 1, wall);

        for (long i = min(beg + dp[n - 1], MAX); i < amm; i++) {
            nums[i][ind + 1] = 0;
        }
    }
    if (ind + 2 < wall) {
        write(min(beg + dp[n - 1], MAX), amm, ind + 2, n - 2, wall);
    }
}

int main() {
    long amm, k;
    int n;

    scanf("%d %ld", &n, &k);
    amm = power(n);

    if (k > amm) {
        printf("-1");
        return 1;
    }

    write(0, dp[n], 0, n, n);

    for (int i = 0; i < n; i++) {
        printf("%d", nums[k - 1][i]);
    }

    return 0;
}