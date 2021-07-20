#include <stdio.h>

int main() {
    int m1, m2;
    scanf("%d %d", &m1, &m2);

    if (m1 == 1) {
        m1 = 2;
    }
    int ammount = 0;
    for (int i=m1; i<=m2; i++){
        int sum=1;
        for (int j=2; j*j<=i; j++){
            if (i%j == 0) {
                sum = sum + j + (i/j);
            }
        }
        if (sum == i) {
            ammount++;
        }
    }
    printf("%d\n", ammount);

    while (ammount > 0) {
        for (int i=m1; i<=m2; i++){
            int sum=1;
            for (int j=2; j*j<=i; j++){
                if (i%j == 0) {
                    sum = sum + j + (i/j);
                }
            }
            if (sum == i) {
                printf("%d ", i);
                ammount--;
            }
        }
    }
}