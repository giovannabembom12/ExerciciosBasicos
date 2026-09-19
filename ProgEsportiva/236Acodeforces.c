#include <stdio.h>
#include <stdlib.h>

int main(){
    char user[101];

    int letras[26]={0};
    int distintos=0;

    scanf("%s", &user);

    int tamanho = strlen(user);
    for(int i=0; i<tamanho; i++){
        int index = user[i] - 'a';
        if(letras[index]==0){
            letras[index]=1;
            distintos++;
        }
    }

    if(distintos%2==0){
        printf("CHAT WITH HER!\n");
    }else{
        printf("IGNORE HIM!\n");
    }

    return 0;

}