#include <stdio.h>
#include <stdlib.h>

int main(){
    long long n;
    scanf("%lld", &n);

    if(n%3==0){
        printf("1 1 %lld\n", n - 2);
    } else{
        printf("1 2 %lld\n", n-3);
    }

    return 0;
}