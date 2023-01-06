#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numero, termo, fatorial;

   printf("Calculo do Fatorial \n\n");
   scanf("%d",&numero);

   if (numero < 0){
    printf("numero Invalido \n");
   }
   else{

    fatorial = 1;
    for (termo=numero;termo>=2;termo--){
        fatorial=fatorial*termo;

    }
    printf("\n O fatorial do Numero %d e %d", numero, fatorial);
   }
    return 0;
}
