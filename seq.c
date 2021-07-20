#include <stdio.h>


char S[50];
char s[50];

int main() {
    scanf("%s", S);

    char lrgst = '\0';
    int ind = 0, i = 0, mem;
    while (i < 50) {
        if (ind == 50 || S[ind] == '\0') {
            break;
        }
        while (S[ind] != '\0') {
            if (S[ind] > lrgst) {
                lrgst = S[ind];
                mem = ind;
            }
            ind++;
        }
        s[i] = lrgst;
        i++;
        lrgst = '\0';
        ind = mem + 1;
    }
    printf("%s", s);
    return 0;
}