#include <stdio.h>

int main() {
    int pRosa, pAzul, a;
    scanf("%d %d %d", &pRosa, &pAzul, &a);
    
    if (pRosa == 0 || pAzul == 0) {
        printf("0\n");
        return 0;
    }
    
    long long x = a / 2;         
    long long y = a - x;
    long long produto = x * y;
    long long resultado = (long long)pRosa * pAzul * produto;
    
    printf("%lld\n", resultado);
    return 0;
}