#include <stdio.h>
#include <stdlib.h>


int check(int cands[], int ignore[], int n, int n_i, unsigned int g) {
    unsigned int res = 0;
    for (int ind = 0; ind < n; ind++) {
        int flag = 0;
        for (int k = 0; k < n_i; k++) {
            if (cands[ind] == ignore[k]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        res = res | cands[ind];
    }
    return res == g;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

void brute(int cands[], int index, int n, int subset[], int n_i, int res[], unsigned int g) {
    if (index == n) {
        if (!check(cands, subset, n, n_i, g)) {
            res[0] = min(res[0], n_i);
        }
        return;
    }
    subset[n_i] = cands[index];
    brute(cands, index + 1, n, subset, n_i, res, g);
    subset[n_i] = cands[index];
    brute(cands, index + 1, n, subset, n_i + 1, res, g);
}

int res[1];

int main() {
    int n;
    unsigned int g;
    scanf("%d %u", &n, &g);

    int *T = (int *) malloc(n * sizeof(unsigned int));
    int *cands = (int *) malloc(n * sizeof(unsigned int));
    for (int i = 0; i < n; i++) {
        scanf("%u", &T[i]);
    }

    int ind = 0;
    for (int i = 0; i < n; i++) {
        if ((T[i] | g) == g) {
            cands[ind] = T[i];
            ind++;
        }
    }
    unsigned int ans = 0;
    for (int i = 0; i < ind; i++) {
        ans = ans | cands[i];
    }
    if (ans != g) {
        printf("0");
        return 0;
    }

    int *subset = (int *) malloc(ind * sizeof(unsigned int));
    res[0] = ind;

    brute(cands, 0, ind, subset, 0,  res, g);
    printf("%d", res[0]);

    return 0;
}