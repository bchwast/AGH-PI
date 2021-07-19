#include <stdio.h>

int main() {
    int n, a, b;
    a = 0;
    b = 1;
    scanf("%d", &n);

    while (a*b < n) {
        int temp = a;
        a = b;
        b += temp;
    }

    if (a*b == n){
        printf("YES");
    }
    else {
        printf("NO");
    }
}