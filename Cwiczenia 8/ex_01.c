#include <stdio.h>

int X[18];

long long ones(int a){
    long long res = 1;
    while (a > 0) {
        res *= 10;
        res++;
        a--;
    }
    return res;
}

int main() {
   long long S, tmp = 0;
   scanf("%lld", &S);

   int ind = 0;
   long long add = 9;
   while (tmp <= S) {
       X[ind] = 9;
       tmp += add;
       add *= 10;
       add += 9;
       ind++;
   }
   ind--;
   int len = ind;

   while (1) {
       while (tmp > S && X[ind] > 0) {
           tmp -= ones(ind);
           if (tmp >= S) {
               X[ind]--;
               if (tmp == S) {
                   for (int i = len; i >= 0; i--) {
                       printf("%d", X[i]);
                   }
                   return 0;
               }
           }
           else {
               tmp += ones(ind);
               break;
           }
       }
       if (ind == 0) {
           printf("-1");
           return 0;
       }
       ind--;
   }
}
