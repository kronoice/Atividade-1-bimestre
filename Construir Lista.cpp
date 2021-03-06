#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "Construir Lista.h"

struct lista {
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* constroi(int *v, int n) {
	int i;
	Lista *l = (Lista*)malloc(sizeof(Lista));
	l = NULL;
	for (i = 0; i < 5; i++) {
		if (l == NULL) {
			Lista*novo = (Lista*)malloc(sizeof(Lista));
			novo->info = v[i];
			novo->prox = NULL;
			l = novo;
		}
		else {
			Lista*novo = (Lista*)malloc(sizeof(Lista));
			novo->info = v[i];
			Lista*aux = l;
			while (aux->prox != NULL) {
				aux = aux->prox;
			}
			aux->prox = novo;
		}
		return l;
	}
}

	void imprime(Lista *l){ 
		Lista*aux = l;
		while (aux != nullptr) {
			printf_s("%d", l->info);
			l = l->prox;
		}
	}
	int main(void) {
		int n[5];
		Lista*l = (Lista*)malloc(sizeof(Lista));
		for (int i = 0; i < 5; i++) {
			printf("DIGA V[%d]: ", i);
			scanf_s("%d", &n[i]);
		}
		l = constroi(n, 5);
		imprime(l);
	}
