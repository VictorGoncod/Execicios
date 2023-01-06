int main()
{
    int qtdAl=0;
    char aluno[qtdAl][100];
    float n1[qtdAl], n2[qtdAl], n3[qtdAl];
    int media[qtdAl], cont=0;

    printf("Entre com a quantidade de Alunos: ");
    scanf("%d", &qtdAl);

    for(int i=0; i<qtdAl; i++)
    {
            printf("\nEntre com o nome do aluno: ");
            scanf("%s", &aluno[i]);
            printf("Entre a primeira nota deste aluno: ");
            scanf("%f", &n1[i]);
            printf("Entre a segunda nota deste aluno: ");
            scanf("%f", &n2[i]);
            printf("Entre a terceira nota deste aluno: ");
            scanf("%f", &n3[i]);
            media[i]=(n1[i]+n2[i]+n3[i])/3;
    }
    for(int i=0; i<qtdAl; i++)
    {
            if(media[i]>5)
            {
                          cont++;
            }
    }
    if(cont==0)
    {
               printf("\n\nNenhum aluno obteve media acima de 5!\n\n");
               }
               else{
                    printf("\n\nQuantidade de alunos com media acima de 5: %d ", cont);
                    printf("\n\n");
               }




system("PAUSE");
return -1;
}
