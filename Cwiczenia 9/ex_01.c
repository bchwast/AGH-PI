#include <stdio.h>
#include <string.h>

char s[51];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
char strs[2500][51];

int main() {
    int n;
    scanf("%s", s);

    for (int i = 0; i < 50; i++) {
        if (s[i] == '\0') {
            break;
        }
        n++;
    }

    int ind = 0;
    for (int o = 0; o < n; o++) {
        for (int p = 0; p < 15; p++) {
            if (primes[p] < n) {
                for (int i = 0; i < n; i++) {
                    strs[ind][i] = s[(o + i * primes[p]) % n];
                }
                ind++;
            }
        }
    }

    int min = 0;
    for (int i = 1; i < 2500; i++) {
        if (strs[i][0] != '\0') {
            if (strcmp(strs[i], strs[min]) == -1) {
                min = i;
            }
        }
    }

    printf("%s", strs[min]);

    return 0;
}
