#include <stdio.h>

long long _d[10500];
long long* d = _d + 250;

const int N = 66;
const long long F_n = 27777890035288L;
const long long F_n_plus_1 = 44945570212853L;

int main(){
    int n;
    scanf("%d", &n);


    for (int i = 0; i < n; i++){
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);

        d[tmp1] = tmp2;
    }

    for (int i = 10200; i > -250; --i){
        if (d[i] >= F_n_plus_1 && d[i-1] >= F_n) {
            d[i] -= F_n_plus_1;
            d[i-1] -= F_n;
            d[i+N] += 1;
        }

        d[i - 1] += d[i];
        d[i - 2] += d[i];
        d[i] = 0;
    }

    for (int i = -250; i < 10250; i++){
        if (d[i] != 0) {
            printf("%d ", i);
        }
    }

    return 0;
}