#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x, y, soma;
    printf("Digite um numero: \n");
    scanf("%d",&x);
    
    printf("Digite um outro Numero: \n");
    scanf("%d",&y);
    
    soma = x + y;
    
    printf("O resultado da %d ",soma);
    return 0;
}
