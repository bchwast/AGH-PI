#include <stdio.h>
#include <stdlib.h>


int res(int n, int num[], int** gate) {
    if (n < 0) {
        return num[(n * -1) - 1];
    }
    return res(gate[n - 1][0], num, gate) ^ res(gate[n - 1][1], num, gate);
}

void increment(int num[], int len) {
    num[len - 1]++;
    int ind = len - 1;
    while (1) {
        if (num[ind] > 1) {
            num[ind] = 0;
            num[ind - 1]++;
        }
        else {
            return;
        }
        ind--;
    }
}

int eq(int num[], int top[], int len) {
    for (int i = 0; i < len; i++) {
        if (num[i] != top[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m, exit, cnt = 0;
    scanf("%d %d %d", &n, &m, &exit);

    int **gate = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        gate[i] = (int *) malloc(2 * sizeof(int));
        scanf("%d %d", &gate[i][0], &gate[i][1]);
    }
    int *num = (int *) malloc(n * sizeof(int));
    int *top_n = (int *) malloc(n * sizeof(int));
    char *top = (char *) malloc(n * sizeof(char));
    char *bot = (char *) malloc(n * sizeof(char));
    scanf("%s", bot);
    scanf("%s", top);
    for (int i = 0; i < n; i++) {
        num[i] = ((int) bot[i]) - 48;
        top_n[i] = ((int) top[i]) - 48;
    }

    while (! eq(num, top_n, n)) {
        cnt += res(exit, num, gate);
//        for (int i = 0; i < n; i++){
//            printf("%d", num[i]);
//        }
//        printf("\n");
        increment(num, n);
    }
    cnt += res(exit, num, gate);

    printf("%d", cnt);

    return 0;
}
