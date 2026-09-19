#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N;
    scanf("%d", &N);
    char resultados[N];

    for (int i = 0; i < N; i++) {
        char s[101];
        scanf("%s", s);
        int tamanho = strlen(s);

        if (tamanho <= 10) {
            resultados[i] = 'N';
            continue;
        }

        int temDigito = 0, temLetra = 0;
        for (int j = 0; j < tamanho; j++) {
            if (isdigit(s[j])) temDigito = 1;
            if (isalpha(s[j])) temLetra = 1;
        }
        if (!temDigito || !temLetra) {
            resultados[i] = 'N';
            continue;
        }

        int primeiraLetra = -1;
        for (int j = 0; j < tamanho; j++) {
            if (isalpha(s[j])) {
                primeiraLetra = j;
                break;
            }
        }

        int digitoPosLetra = 0;
        for (int j = primeiraLetra + 1; j < tamanho; j++) {
            if (isdigit(s[j])) {
                digitoPosLetra = 1;
                break;
            }
        }
        if (digitoPosLetra) {
            resultados[i] = 'N';
            continue;
        }

        int ordemNaoDecrescente = 1;
        for (int j = 1; j < primeiraLetra; j++) {
            if (s[j] < s[j-1]) {
                ordemNaoDecrescente = 0;
                break;
            }
        }
        if (!ordemNaoDecrescente) {
            resultados[i] = 'N';
            continue;
        }

        for (int j = primeiraLetra + 1; j < tamanho; j++) {
            if (s[j] < s[j-1]) {
                ordemNaoDecrescente = 0;
                break;
            }
        }
        if (!ordemNaoDecrescente) {
            resultados[i] = 'N';
            continue;
        }

        resultados[i] = 'S';
    }

    for (int i = 0; i < N; i++) {
        printf("%c\n", resultados[i]);
    }

    return 0;
}