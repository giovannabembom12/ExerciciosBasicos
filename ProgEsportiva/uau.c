#include <stdlib.h>
#include <stdio.h>

int main(){
    int uau;

    scanf("%d", &uau);

    if(4<=uau && uau<=100 && uau%2==0){
            printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;
}