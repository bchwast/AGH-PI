#include <stdio.h>
#define MAX 20
#define SYM 13

char num1[] = "!!!!!!!!!!!!!!!!!!!!";
char num2[] = "!!!!!!!!!!!!!!!!!!!!";
int base[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
char *sym[SYM];

int value(char dig) {
    if (dig == 'I') return 1;
    if (dig == 'V') return 5;
    if (dig == 'X') return 10;
    if (dig == 'L') return 50;
    if (dig == 'C') return 100;
    if (dig == 'D') return 500;
    if (dig == 'M') return 1000;
}

int main() {
    int n1 = 0, n2 = 0, sum;

    sym[0] = "I";
    sym[1] = "IV";
    sym[2] = "V";
    sym[3] = "IX";
    sym[4] = "X";
    sym[5] = "XL";
    sym[6] = "L";
    sym[7] = "XC";
    sym[8] = "C";
    sym[9] = "CD";
    sym[10] = "D";
    sym[11] = "CM";
    sym[12] = "M";

    for (int i = 0; i < MAX; i++) {
        char dig;
        scanf("%c", &dig);
        if (dig == ' ') {
            break;
        }
        else {
            num1[i] = dig;
        }
    }
    for (int i = 0; i < MAX; i++) {
        char dig;
        scanf("%c", &dig);
        if (dig == '\n') {
            break;
        }
        else {
            num2[i] = dig;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (num1[i] == '!') break;

        int dig1 = value(num1[i]);
        n1 += dig1;

        if (num1[i + 1] != '!') {
            int dig2 = value(num1[i + 1]);

            if (dig1 < dig2) {
                n1 += dig2;
                n1 -= (2 * dig1);
                i++;
            }
        }
    }
    for (int i = 0; i < MAX; i++) {
        if (num2[i] == '!') break;

        int dig1 = value(num2[i]);
        n2 += dig1;

        if (num2[i + 1] != '!') {
            int dig2 = value(num2[i + 1]);

            if (dig1 < dig2) {
                n2 += dig2;
                n2 -= (2 * dig1);
                i++;
            }
        }
    }

    sum = n1 + n2;
    int i = 12;
    while (sum > 0) {
        int div = sum / base[i];
        sum = sum % base[i];

        while (div > 0) {
            printf("%s", sym[i]);
            div--;
        }
        i--;
    }

    return 0;
}