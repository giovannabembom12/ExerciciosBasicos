#include <string.h>
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    char palavra[101];
    for(int i=0; i<n; i++){
        scanf("%s", palavra);

        int tamanho = strlen(palavra);
        if(tamanho>10){
            printf("%c%d%c\n", palavra[0], tamanho-2, palavra[tamanho-1]);
        } else{
            printf("%s\n", palavra);
        }
    }

    return 0;
}