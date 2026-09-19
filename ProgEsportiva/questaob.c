#include <stdio.h>
 
int main() {
    int N, P, K;
    scanf("%d %d %d", &N, &P, &K);
    
    int posicaoinicial = P;          
    int contador = 0;            
    
    while (1) {
        posicaoinicial = posicaoinicial % N + 1;   
        if (posicaoinicial == P) continue;  
        contador++;                     
        if (contador == K + 1) {       
            printf("%d\n", posicaoinicial);
            break;
        }
    }
    
    return 0;
}