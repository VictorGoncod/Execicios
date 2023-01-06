#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_t {
	int value;
	struct Node_t* next;
	struct Node_t* prev;
} Node;

Node* node_new(int value) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;
	node->next = node->prev = NULL;
	return node;
}

typedef struct DList_t {
	Node* head;
	Node* tail;
} DList;

DList* dlist_new() {
	DList* list = (DList*) malloc(sizeof(DList));
	list->head = list->tail = NULL;
	return list;
}

void dlist_insert_head(DList* list, int value) {
	Node* node = node_new(value);
	if (list->head == NULL) {
		list->head = list->tail = node;
	} else {
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
}

void dlist_insert_tail(DList* list, int value) {
	Node* node = node_new(value);
	if (list->head == NULL) {
		list->head = list->tail = node;
	} else {
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
}

void dlist_insert_sorted(DList* list, int value) {
	Node* node = node_new(value);
	if (list->head == NULL) {
		list->head = list->tail = node;
	} else {
		Node* tmp = list->head;
		// Encontra o nó, cujo valor é menor ou igual ao
		// valor requisitado.
		while (tmp->next != NULL && tmp->value <= value) {
			tmp = tmp->next;
		}

		// Valor do nó atual é maior ou igual que o novo valor:
		// Insere antes
		if (tmp->value >= value) {
			// 1.
			// [2]  [1] <-> [3] <-> [5
			// 2.
			// [1] - [2] - [3] <-> [5]
			if (tmp->prev != NULL) {
				// 3.
				// [1] <-> [2] - [3] <-> [5]
				tmp->prev->next = node;
				node->prev = tmp->prev;
			}
			// 4.
			// [1] <-> [2] <-> [3] <-> [5]
			node->next = tmp;
			tmp->prev = node;
			if (tmp == list->head) {
				list->head = node;
			}

		// Valor do nó atual é menor que o novo valor:
		// Insere depois
		} else if (tmp->value < value) {
			if (tmp->next != NULL) {
				tmp->next->prev = node;
				node->next = tmp->next;
			}
			node->prev = tmp;
			tmp->next = node;
			if (tmp == list->head) {
				list->head = node;
			}
		}
	}
}

Node* dlist_find_node(DList* list, int value) {
	if (list->head == NULL) return NULL;
	if (list->head == list->tail) return list->head; // 1 elemento
	Node* currH = list->head;
	Node* currT = list->tail;

	// Move os ponteiros Inicio e Fim até que um
	// dos dois ache o valor requisitado.
	//  I============>               <===========F
	// [1] <-> [5] <-> [6] <-> [10] <-> [3] <-> [9]
	while (currH != currT) {
		if (currH != NULL && currH->value == value)
			return currH;
		else if (currH != NULL)
			currH = currH->next;

		if (currT != NULL && currT->value == value)
			return currT;
		else if (currT != NULL)
			currT = currT->prev;
	}
	return NULL;
}

bool dlist_remove(DList* list, int value) {
	Node* node = dlist_find_node(list, value);
	if (node == NULL) return false;

	if (node->prev == NULL) { // Remove do Inicio
		Node* tmp = list->head;
		list->head = list->head->next;
		list->head->prev = NULL;
		free(tmp);
		return true;
	} else if (node->next == NULL) { // Remove do Fim
		Node* tmp = list->tail;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		free(tmp);
		return true;
	} else {
		Node* prev = node->prev;
		Node* next = node->next;
		prev->next = next;
		next->prev = prev;
		free(node);
		return true;
	}
	return false;
}

bool dlist_find(DList* list, int value) {
	return dlist_find_node(list, value) != NULL;
}

void dlist_print(DList* list) {
	printf("[");
	Node* curr = list->head;
	while (curr != NULL) {
		if (curr->next == NULL) {
			printf("%d", curr->value);
		} else {
			printf("%d, ", curr->value);
		}
		curr = curr->next;
	}
	printf("]\n");
}

void dlist_clear(DList* list) {
	Node* curr = list->tail;
	while (curr != NULL) {
		Node* prev = curr->prev;
		free(curr);
		curr = prev;
	}
	list->head = list->tail = NULL;
}

int main(int argc, char** argv) {
    srand(time(NULL));

	printf("=== Lista Duplamente Encadeada ===\n\n");

	DList* list = dlist_new();

	for (int i = 0; i < 50; i++) {
		dlist_insert_sorted(list, rand() % 50);
	}

	printf("=== Insercao Ordenada ===\n");
	dlist_print(list);

	printf("=== Busca ===\n\tValor: ");
	int val = -1;
	scanf("%d", &val);
	if (dlist_find(list, val)) {
		printf("\t[ Valor Encontrado! ]\n");
	} else {
		printf("\t[ Valor Nao Encontrado! ]\n");
	}

	dlist_clear(list);

	for (int i = 0; i < 10; i++) {
		dlist_insert_tail(list, rand() % 10);
	}

	printf("=== Insercao ===\n");
	dlist_print(list);

	for (int i = 0; i < 10; i++) {
	    int rem = rand() % 10;
		if (dlist_remove(list, rem)) {
		    printf("\tRemovido: %d\n", rem);
		}
	}

	printf("=== Remocao ===\n");
	dlist_print(list);

	dlist_clear(list);
	free(list);

	return 0;
}
