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
