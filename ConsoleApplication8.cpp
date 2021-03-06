#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

struct lista {
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa(void){
	return NULL;
}

Lista* inserir(Lista* lst, int v) {
	Lista *novo = (Lista *)malloc(sizeof(Lista));

	novo->info = v;
	novo->prox = lst;

	return novo;
}

Lista* separa(Lista* l, int v)
{
	Lista* p;
	Lista* q;
	for (p = l; p != NULL; p = p->prox)
		if (p->info == v)
		{
			q = p->prox;
			p->prox = NULL;
			return q;
		}
	return NULL;
}

void imprime(Lista* l) {

	Lista *p = l;
	int no = 1;

	while (p != NULL) {
		printf("No %2d - End: (%p) Vlr: %3d Prox:(%p) ->\n", no, p, p->info, p->prox);
		p = p->prox;
		no++;
	}
	printf("\n");
}

int main()
{
	Lista* Lista1;

	Lista1 = inicializa();
	
	Lista1 = inserir(Lista1, 17);
	Lista1 = inserir(Lista1, 3);
	Lista1 = inserir(Lista1, 5);
	Lista1 = inserir(Lista1, 12);
	Lista1 = inserir(Lista1, 1);

	printf("Antes...\n");
	imprime(Lista1);

	Lista1 = separa(Lista1, 1);
	Lista1 = separa(Lista1, 12);
	
	printf("Depois...\n");
	imprime(Lista1);


	system("pause");

	return 0;
}
