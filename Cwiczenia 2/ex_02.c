#include <stdio.h>
#define MAX 8

int power(int a, int b) {
    int result = 1;
    for (int i = 1; i <= b; i++) {
        result *= a;
    }
    return result;
}

int main () {
    int m, b, digit, copy, sum, index;
    char result[MAX], dig;
    scanf("%d %d", &m, &b);

    int down = power(b, m - 1);
    int up = power(b, m);
    int present = 0;

    for (int number = down; number < up; number++) {
        copy = number;
        sum = 0;

        while (copy > 0) {
            digit = copy % b;
            sum += power(digit, m);
            copy /= b;
        }

        if (sum == number) {
            present = 1;
            copy = number;
            index = m - 1;
            while (copy > 0) {
                digit = copy % b;
                if (digit > 9) {
                    dig = 55 + digit;
                    result[index] = dig;
                }
                else {
                    dig = 48 + digit;
                    result[index] = dig;
                }
                copy /= b;
                index--;
            }

            for (int i = 0; i < m; i++) {
                printf("%c", result[i]);
            }
            printf(" ");
        }
    }

    if (present == 0) {
        printf("NO");
    }

    return 0;
}