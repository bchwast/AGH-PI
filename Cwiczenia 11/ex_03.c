#include <stdio.h>
#include <string.h>


int min = 9999999;
char res[100];

int brute(int n, char temp[], int i, int t) {
    if (i > 98) {
        return 0;
    }
    if (n == t) {
        if (i < min) {
            min = i;
            strcpy(res, temp);
        }
        else if (i == min) {
            if (strcmp(temp, res) < 0) {
                strcpy(res, temp);
            }
        }
        return 1;
    }
    if (n <= 0 || n > t) {
        return 0;
    }
    if (n < t) {
        if (n + n <= t) {
            temp[i] = '+';
            brute(n + n, temp, i + 1, t);
        }
        if (n * n <= t) {
            temp[i] = '*';
            brute(n * n, temp, i + 1, t);
        }
        return 0;
    }
    return 0;
}

int main() {
    int s, t;
    scanf("%d %d", &s, &t);
    if (t == 0) {
        printf("-");
        return 0;
    }
    if (t == 1) {
        printf("/");
        return 0;
    }
    char tmp[100];
    brute(s, tmp, 0, t);
    int prev = min;

    brute(1, tmp, 0, t);
    if (min == 9999999) {
        printf("NO");
        return 0;
    }
    if (min < prev) {
        printf("/");
    }
    for (int i = 0; i < min; i++) {
        printf("%c", res[i]);
    }
    return 0;
}