#include <stdio.h>
#include <stdlib.h>
struct Candidato{
    int matricula;
    float nota;
}inscritos[100], classificados[100];

    void inicializa(){
       for(int i=0; i<100; i++){
         inscritos[i].matricula=-1;
         inscritos[i].nota=0.0;
         classificados[i].matricula=-1;
         classificados[i].nota=0.0;
       }
    }
    int buscar(int matricula){
        for(int i=0; i<100; i++){
        if(inscritos[i].matricula!=-1 && inscritos[i].matricula==matricula ){
        return i;
        break;
}
}
       return -1;
}
    int inserir(int matricula, float nota ){
        if(buscar(matricula)==-1){
        for(int i=0; i<100; i++){
        if(inscritos[i].matricula==-1){
            inscritos[i].matricula=matricula;
            inscritos[i].nota=nota;
            classificados[i].matricula=matricula;
            classificados[i].nota=nota;
        return 0;
        break;
}
}
}
       return -1;
}
    int excluir(int matricula){
        for(int i=0; i<100; i++){
        if(inscritos[i].matricula!=-1 && inscritos[i].matricula==matricula){
            inscritos[i].matricula=-1;
            inscritos[i].nota=0.0;
        return 0;
        break;
}
}
        return -1;
}
    int verificaEspacoInscritos(){
        for(int i=0; i<100; i++){
        if(inscritos[i].matricula==-1){
        return 0;
        break;
}
}
        return-1;
}
    int maiorNotaEExclui(){
       int posicao=0;
       int semCadatro=-1;

       for(int i=0; i<100; i++){
       if(inscritos[i].matricula!=-1){
          semCadatro=0;
       break;
}
}
       if(semCadatro==0){
       float maior=0;
            for(int i=0; i<100; i++){
            if(inscritos[i].nota > maior ){
               posicao=i;
               maior=inscritos[i].nota;
}
}
        return posicao;

       }else{
        return -1;
}
}
    int buscarClassificados(int matricula){
       for(int i=0; i<100; i++){
       if(classificados[i].matricula!=-1 && classificados[i].matricula==matricula ){
       return i;
       break;
}
}
       return -1;
}
    int verificaEspacoClassificados(){
        for(int i=0; i<100; i++){
        if(classificados[i].matricula==-1){
        return 0;
        break;
}
}
        return-1;
}
    int verificaSeHaClassificados(){
       for(int i=0; i<100; i++){
       if(classificados[i].matricula!=-1){
       return 0;
       break;
}
}
       return -1;
}
    int enfileirar(int matricula, float nota ){
        if(buscarClassificados(matricula)==-1 || verificaEspacoClassificados()==0){
        for(int i=0; i<100; i++){
        if(classificados[i].matricula==-1){
           classificados[i].matricula=matricula;
           classificados[i].nota=nota;
        return 0;
        break;
}
}
}
       return -1;
}
    int maiorNotaEExcluiCandidatos(){
        int posicao=0;
        int semCadatro=-1;

        for(int i=0; i<100; i++){
        if(classificados[i].matricula!=-1){
           semCadatro=0;
        break;
}
}
       if(semCadatro==0){
       float maior=0;
       for(int i=0; i<100; i++){
       if(classificados[i].nota > maior ){
          posicao=i;
          maior=classificados[i].nota;
}
}
        return posicao;

       }else{
        return -1;
}
}
    void ordernar(){
      struct Candidato aux[100];
      for(int j=0; j<100; j++){
          aux[j].matricula=-1;
          aux[j].nota=0.0;
}
      for(int i=0; i<100; i++){
         aux[i].matricula=classificados[maiorNotaEExcluiCandidatos()].matricula;
         aux[i].nota=classificados[maiorNotaEExcluiCandidatos()].nota;
            classificados[maiorNotaEExcluiCandidatos()].matricula=-1;
            classificados[maiorNotaEExcluiCandidatos()].nota=0.0;
}
      for(int k=0; k<100;k++){
          classificados[k].matricula=aux[k].matricula;
          classificados[k].nota=aux[k].nota;
}
}
      int main()
{
          inicializa();

      int op;
      do{
         printf("\n\n----------SELECIONE UMA DAS OPCOES---------- \n\n 1-Cadastrar Candidato \n 2-Gerar Classificacao\n 3-Lista de Convocados\n 4-Sair\n--------------------------------------------\n *Selecionar: ");
         scanf("%d", &op);
         system("cls");
      switch (op){
      case 1:
      if(verificaEspacoInscritos()==0){
         printf("*Digite a Matricula*\n=");
      int matricula;
          scanf("%d", &matricula);
          printf("*Digite a Nota*\n=");
      float nota;
          scanf("%f", &nota);
      if(inserir(matricula, nota)== 0){
          printf("*Cadastrado com Sucesso*");
      }else{
          printf("*Este Candidato ja esta Cadastrado*");
}
      }else{
          printf("*Nao ha Espaco para Novos Cadastros*");
}
       break;

       case 2:
          printf("Classificacao:\n");
       if(verificaSeHaClassificados()==0){
          ordernar();
       for(int i=0; i<100; i++){
          printf("\n Matricula: %d \n Nota: %2.f \n", classificados[i].matricula, classificados[i].nota  );
}
       }else{
          printf("Nao ha Candidados para serem Classificados" );
}
        break;
        case 3:
          printf("Lista de Convocados:\n");
        if(verificaSeHaClassificados()==0){
          ordernar();
        for(int i=0; i<30; i++){
          printf("\n Matricula: %d \n Nota: %2.f \n", classificados[i].matricula, classificados[i].nota  );
}
        }else{
          printf("Nao ha Candidados para serem Classificados" );
}
         break;
         default:
          op=0;
          printf("**Saindo...**\n");
         break;
}
        }while(op!=0);
         return 0;
}
