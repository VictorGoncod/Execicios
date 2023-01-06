#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct no{
	int info;
	int antecessor;
	int sucessor;
	struct no *prox;
	struct no *ant;
};typedef struct no *lista;

lista inicio = NULL;
lista fim = NULL;

bool listavazia( ){
	if(inicio){
		return false;
	}else {
		return true;
	}
}


void insere(){
	lista p;
	p = new no;
	cout<<"Insira um numero na lista ";
	cin>>p->info;
	p->prox = NULL;
	cout<<"Numero "<<p->info<<" inserido na lista\n\n";
	if(listavazia()){
		inicio = p;
		fim = p;
	} else{
		inicio->prox = p;
		p->ant = inicio;
		p->prox = NULL;
		fim = p;
	}
}

void retira() {
	lista p=inicio, aux= p->prox, post=NULL;
	int num;

	cout<<"Qual numero sera excluido\n\n";
	cin>>num;
	if(listavazia()){
		cout<<"A lista esta vazia!\n\n";
	}else{
		while(p!=NULL){
			if(num == p->info && p->ant == NULL){
				aux = p->prox;
				aux->ant = inicio;
				inicio = aux;
				delete(p);
				cout<<"\n\nNo retirado.";
				}else if(num == p->info && p->prox == NULL){
					aux = p->ant;
					fim = aux;
					aux->prox = NULL;
					delete(p);
					cout<<"\n\nNo retirado";
				}else{
					aux = p->ant;
					post = p->prox;
					aux->prox = post;
					post->ant = aux;
					delete(p);
				}
		}
	}
}

void listar(){
	lista p=inicio;

		if(!listavazia()){
		cout<<"A lista esta assim: \n\n";
		while(p!=NULL){
			cout<<"\t||"<<p->info;
			p=p->prox;
		}
		}else{
			cout<<"A lista esta vazia!!\n\n";
		}

	}

void menor_elemento(){
	lista p=inicio, aux=inicio->prox,menor=NULL;

	if(listavazia()){
		cout<<"Lista Vazia";
	}else{
		while(p!=NULL){
			if(p->info < aux->info){
				menor = p;
				menor->ant = p->ant;
				menor->prox = p->prox;
				cout<<"\n\nMenor elemento da lista: "<<menor->info;
				cout<<"\nSeu elemento anterior: "<<menor->ant->antecessor;
				cout<<"\nSeu elemento sucessor: "<<menor->prox->sucessor;
				p = p->prox;
				aux = aux->prox;
			}else if(p->info > aux->info){
			menor = aux;
			menor->ant = aux->ant;
			menor->prox = aux->prox;
			cout<<"\n\nMenor elemento da lista: "<<menor->info;
			cout<<"\nSeu elemento anterior: "<<menor->ant->antecessor;
			cout<<"\nSeu elemento sucessor: "<<menor->prox->sucessor;
			p = p->prox;
			aux = aux->prox;
		}
	}
}
}

void menu(int op) {

	do{


	cout<<"\n----MENU----\n\n";
	cout<<"--1--Inserir na Lista\n\n";
	cout<<"--2--Remover item da Lista\n\n";
	cout<<"--3--Listar elementos da Lista\n\n";
	cout<<"--4--Listar menor elemento da lista, seu antecessor e seu sucessor.\n\n";
	cout<<"--0--Sair\n\n";
	cin>>op;


	switch(op){

		case 1: insere();
			break;

		case 2: retira();
			break;

		case 3: listar();
			break;

		case 4: menor_elemento();
			break;

	}

}while(op!=0);
}





int main(){

	int op;

	menu(op);

}
