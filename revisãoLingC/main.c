#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota1, nota2, nota3, media, somamedias=0, mediageral;
    int quantalunos;

    for(quantalunos=0; quantalunos<3; quantalunos++){

        printf("Digite as 3 notas: \n");
        scanf("%f%f%f",&nota1,&nota2,&nota3);

        media = (nota1+nota2+nota3)/3;

        if(media>=7){
            printf("Aprovado com Media %f\n",media);
          }else{
              if(media<4){
                printf("Reprovado com media %f\n",media);
                }else{
                  printf("Precisa fazer final. Media do Semestre %f", media);
               }
             }

         //quantalunos = quantalunos+1; // nesta eu estou somando mais um
     //quantalunos++;//nesta eu estou incrementado
     somamedias=somamedias+media;

    }//while(quantalunos);

    mediageral=somamedias/3;
    printf("Media Geral da Turma: %f\n",mediageral);


    return 0;
}

 /*if(media>=4 && media<7)
    {
        printf("Precisa frazer final. Media do Semestre %f\n", media);
    }*/

