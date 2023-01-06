/*************************
  UFFS CHAPEC�
  github.com/barbs-pm
  Barbara Pegoraro Markus
  LISTA DUPLA ENCADEADA
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 100

typedef struct produto{ //struct para cada informa��o do nodo
	int codigo;
	char nome[TAM];
	float preco;
}tp_produto;

typedef struct nodo{ //struct para cada nodo da lista
	tp_produto produto;
	struct nodo *next;
	struct nodo *prev;
}tp_nodo;


typedef struct lista{  //struct da cabe�a da lista
	int nItens;
	tp_nodo *first;
	tp_nodo *last;
}tp_lista;

//fun��o que adiciona um nodo e retorna a lista atualizada
void push(tp_lista *head){
	tp_nodo* novo = (tp_nodo*) malloc(sizeof(tp_nodo)); //aloca um novo nodo

	novo->next = NULL; //o pr�ximo para que o nodo apontar� ser� NULL
	novo->prev = head->last; //o anterior que o nodo vai apontar � o ultimo da cabe�a da lista

	if(head->nItens == 0) head->first = novo; //se o nItens � 0 significa que o first da cabe�a ser� esse nodo
	else (novo->prev)->next = novo; //sen�o o nodo ser� o proximo da lista

	head->last = novo;	//o last da cabe�a ser� esse nodo

	system("clear");  //adicionando as informa��es do nodo
	printf("\t___________~<>~___________\n");
	printf("\tC�digo do produto: ");
	scanf("%d", &novo->produto.codigo);
	printf("\tNome: ");
	getchar();
	fgets(novo->produto.nome, TAM, stdin);
	printf("\tPre�o: ");
	scanf("%f", &novo->produto.preco);

	(head->nItens)++; //n�mero de itens aumenta

}

/**********************
selo anti-pl�gio
code feito por Barbara
***********************/

void pop(tp_lista *head){
	int codiguinho, volta, cont=0;
	/* c�diguinho = comparar o codigo do usuario e do nodo
	   volta = sair da fun��o
	   cont = contador para verificar se existe algum produto
	*/
	tp_nodo *aux, *endereco; //endereco = receber� posi��o atual do p para poder apontar um a frente depois

	if(head->nItens == 0) { //se a lista tiver vazia imprime mensagem
		system("clear");
		printf("\t___________~<>~__________\n");
		printf("\tLista vazia.\n");
		printf("\tAperte 1 para voltar: ");
		scanf("%d", &volta);
	}


	else{
		system("clear");
		printf("\t___________________~<>~__________________\n");
		printf("\tC�digo do produto que deseja retirar: ");
		scanf("%i",&codiguinho);

		for(aux = head->first; aux != NULL; aux = aux->next){  // percorre todos os elementos da lista do primeiro ate
															   //o ultimo apontando sempre pro pr�ximo do atual
			if((aux->produto).codigo == codiguinho){ //compara se o c�digo do produto � igual ao digitado pelo usuario
				cont = 1; //cont recebe um caso ache um produto com o c�digo
				if(aux == head->first){ //se o produto for o primeiro
					endereco = head->first; //endere�o ser� igual o first da lista
					head->first = (head->first)->next; //o first vai apontar para o proximo, "excluindo" o anterior
					endereco->prev = NULL; //o anterior do first ser� NULL
					(head->nItens)--; //numero de itens diminui
				}

				else if(aux == head->last){ //se o produto for o �ltimo
					endereco = head->last; //endere�o ser� o last da lista
					head->last = (head->last)->prev; //o last ser� o seu anterior
					(head->last)->next = NULL; //o proximo do last apontar� para NULL
					(head->nItens)--; //n�mero de itens diminui
				}
				else{ //caso ele esteja no meio
					(aux->next)->prev = aux->prev;//o anterior do proximo ser� o anterior do nodo
					(aux->prev)->next = aux->next;//o proximo do anterior sera o proximo do nodo
					(head->nItens)--;////n�mero de itens diminui
				}
			}
		}

		if(cont == 0){//caso n�o tenha achado produto, o codigo n�o ir� alterar o seu valor
			system("clear");
			printf("\t____________~<>~___________\n");
			printf("\tProduto n�o encontrado\n");
			printf("\tAperte 1 para voltar: ");
			scanf("%d", &volta);
		}
	}
}

/**********************
selo anti-pl�gio
code feito por Barbara
***********************/

void display(tp_lista *head){
	tp_nodo *aux;
	int volta;

	system("clear");


	printf("\t___________~<>~__________\n");

	for(aux = head->first; aux != NULL; aux = aux->next){
		printf("\tC�digo do produto: %d\n", (aux->produto).codigo);
		printf("\tNome: %s", (aux->produto).nome);
		printf("\tPre�o: %.2f", (aux->produto).preco);
		printf("\n\n");
	}
	printf("\t___________~<>~__________\n");

	if(head->nItens == 0) { //se a lista tiver vazia imprime mensagem
		system("clear");
		printf("\t___________~<>~__________\n");
		printf("\tLista vazia.\n");
	}
	printf("\tAperte 1 para voltar: ");
	scanf("%d", &volta);
}

int main(void){
	int op;

	tp_nodo *l = NULL; //cria uma lista vazia
	tp_lista *head = malloc(sizeof(head));

	head->last = NULL;
	head->first = NULL;
	head->nItens = 0;

	do{
		system("clear");
		printf("\t___________~<>~__________\n");
		printf("\t|0| Sair\n");
		printf("\t|1| Inserir produto\n");
		printf("\t|2| Excluir produto\n");
		printf("\t|3| Exibir lista\n");
		printf("\t___________~<>~__________\n");
		printf("\tEscolha sua op��o: ");
		scanf("%d", &op);

		switch(op){
			case 1: push(head); break;
			case 2: pop(head); break;
			case 3: display(head); break;
		}

	} while(op != 0);

	free(l);
	free(head);

	return 0;
}

