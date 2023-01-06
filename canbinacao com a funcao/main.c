#include <stdio.h>
#include <stdlib.h>


int calcular_fatorial(int numero)
{
   int fatorial,termo;

   if(numero<=0)
   {
     fatorial = -1;
   }
   else
   {
       fatorial = 1;
       for(termo=numero; termo>=2; termo--)
       {
           fatorial = fatorial * termo;
       }
   }
   return fatorial;
}
int main()
{
    int p, q, fatp, fatq, fatpq;
    float coficientebinominal;

    printf("Digite o Valor de p\n");
    scanf("%d",&p);

    printf("Digite o valor de q\n");
    scanf("%d",&q);

    fatp = calcular_fatorial(p);
    fatq = calcular_fatorial(q)
    fatpq = calcular_fatorial(p-q);

    if(fatp==-1 || fatq==-1 || fatpq==-1)
    {
        printf("Numeros Invalidos\n");
        printf("P e Q Não podem ser Numeros negativos e P tem que ser maior do que Q\n");
    }
    else
    {
        coficientebinominal = (float)fatp/(fatpq);
        printf("Numero de combinacao de %d elemento %d a %d: %f",p ,q ,q ,coficientebinominal);
    }

    return 0;
}
