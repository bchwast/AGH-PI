#include <stdio.h>


int repr[100];

int main() {
    long long int num, n_num;
    scanf("%lld", &num);
    n_num = num * (-1);

    for (int i = 0; i < 100; i++) {
        repr[i] = 0;
    }

    for (int i = 99; i >= 0; i--) {
        if (num == 0) {
            repr[i] = 5;
            break;
        }
        long long rem = num % -2;
        num /= -2;
        if (rem < 0) {
            rem += 2;
            num++;
        }
        repr[i] = rem;
    }

    for (int i = 99; i >= 0; i--) {
        if (repr[i] == 5) {
            break;
        }
        else if (repr[i] != 0){
            int ind = 99 - i;
            printf("%d ", ind);
        }
    }
    printf("\n");

    for (int i = 0; i < 100; i++) {
        repr[i] = 0;
    }

    for (int i = 99; i >= 0; i--) {
        if (n_num == 0) {
            repr[i] = 5;
            break;
        }
        long long rem = n_num % -2;
        n_num /= -2;
        if (rem < 0) {
            rem += 2;
            n_num++;
        }
        repr[i] = rem;
    }

    for (int i = 99; i >= 0; i--) {
        if (repr[i] == 5) {
            break;
        }
        else if (repr[i] != 0){
            int ind = 99 - i;
            printf("%d ", ind);
        }
    }

    return 0;
}