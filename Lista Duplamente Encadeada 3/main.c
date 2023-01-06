#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//LISTA DUPLAMENTE ENCADEADA

//define a estrutura do modo
typedef struct TipoNo
{
    int info;
    struct TipoNo *proximo;
    struct TipoNo *anterior;
}TNo;

//cria o inicio da lista
typedef struct TipoLista
{
    TNo *inicio = NULL;
    TNo *fim = NULL;
}TLista;

//------------------------------------------------
//Funcao que define a lista como vazia.
 void incializarLista(TLista *pLista)
 {
     pLista->inicio = NULL;
     pLista->fim = NULL;
 }
 //-----------------------------------------------
 //Funcao que insere um elemento do inicio da Lista.

 void inserisNoIncio(TLista *pLista)
 {
     TNo *novoElemento;

     novoElementa = new TNo;

     printf("Informa valor: ");
     scanf("%d", &novoElemento->info);

     novoElemento->proximo = NULL;
     novoElemento->anterior = NULL;

     if (pLista->inicio == NULL)
     {
        pLista->incio = novoElemento;
        pLista->fim = novoElemento;
     }
     else
     {
         pLista->inicio->anterior = novoElemento;
         novoElemento->proximo = pLista->inicio;
         pLista->incio = novoElemento;
     }
 }

 void inserisNoFim (TLista *pLista)
 {
     TNo *novoElemento;

     novoElemento = new TNo;

     printf("Informe o Valor: ");
     scanf("%d", &novoElemento->info);

     novoElemento->proximo = NULL;
     novoElemento->anterior = NULL;

     if (pLista->inicio == NULL)
     {
         pLista->inicio = novoElemento;
         pLista->fim = novoElemento;
     }
     else
     {
         pLista->fim->proximo = novoElemento;
         novoElemento->anterior = pLista->fim;
         pLista->fim = novoElemento;
     }
 }
 //-------------------------------------------------
 //Funcao que imprime toda a lista.

 void apresentarPeloInicio (TLista *pLista)
 {
     TNo *ptr;
     if (pLista->inicio == NULL)
     {
         printf("--- Lista Vazia ---\n\n");
     }
     else
     {
         ptr =pLista->inicio;
         while (ptr !=NULL){
            printf("Info = %d\n", ptr->info);
            ptr = ptr ->proximo;
         }
         printf("---Fim da Lista ---\n\n");
     }
     gerch();
 }

 void apresentarPeloFim (TLista *pLista)
 {
     TNo *ptr;
     if (pLista->fim == NULL)
     {
         printf("--- Lista Vazia ---\n\n");
     }
     // Caso a lista nao esteja vazia
     ptr = pLista->fim;
     while (ptr !=NULL){
        printf("Info = %d\n", ptr->info);
        ptr = ptr->anterior;
     }
     printf("--- Fim da Lista ---\n\n");
     getch();
 }

 //-------------------------------------------------------
 //Fucao que buscar um elemento na Lista.

 TNODO *BuscarDado(int dado)
 {
     TNODO *ptr;
     if (inicio == NULL)
     {
         return NULL; //Lista Vazia
     }
     // Caso a Lista nao esteja vazia
     ptr = inicio;
     while (ptr !=NULL){
        if (ptr->info == dado) //achou !!
        {
            return(ptr);
        }           //retorna um poteiro para o inicio da lista
        else
            ptr = ptr->prox;
     }
     //prinft("o elemento nao se encotra na Lista");
   return NULL;
 }

 int remove_inicio()
 {
     TNODO *elem_atual, *elem_proximo, *elem_anterior;
     int dado;

     printf("Informe Numero a ser removido: ");
     scanf("%d", %dado);

     if (inicio==NULL)
     {
         return 0; //Lista vazia !!!
     }
     else
     {
         //Caso a lista nao esteja vazia
         elem_atual = inicio;
         while (elem_atual !=NULL)
         {
             elem_proximo = elem_atual->prox;
             elem_anterior = elem_atual->ante;
             if (elem_atual->info == dado) //achou !!
                if (elem_anterior != NULL)
                   if(elem_proximo != NULL)
                      {
                          elem_anterior->prox = elem_proximo;
                          elem_proximo->ante = elem_anterior;
                          free(elem_atual);
                          break;
                      }
                      else
                      {
                          elem_anterior->prox = NULL;  //elem_atual->prox;
                          fim = elem_anterior;
                          free(elem_atual);
                          break;
                      }
                      else
                        if (elem_proximo != NULL)
                      {
                          elem_proximo->ante = NULL;
                          inicio = elem_proximo;
                          free (elem_atual);
                          break;
                      }
                      else
                      {
                          free(elem_atual);
                      }
                      else
                        elem_atual = elem_atual->prox;
         }
         printf("O Elemento nao se encontra na Lista\n");
     }
 }































