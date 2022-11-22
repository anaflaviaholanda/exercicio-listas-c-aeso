/* 10. Considere a implementa��o de listas encadeadas utilizando apontadores vista em
sala. Escreva um procedimento Troca(TipoLista* pLista, TipoCelula* p) que, dado um
apontador para uma c�lula qualquer (p), troca de posi��o essa c�lula com a sua c�lula
seguinte da lista, como mostrado na figura abaixo. (Obs. N�o vale trocar apenas o
campo item! Voc� dever� fazer a manipula��o dos apontadores para trocar as duas
c�lulas de posi��o). N�o esque�a de tratar os casos especiais.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista { //lista
 	struct lista *ref;
 	struct lista *fim;
}Lista;

typedef struct celula { //no
 	struct celula *ante;
 	struct celula *prox;
 	int info;
}Celula;

/*
  Procedimento para criar uma lista vazia
*/
void criar_lista(Lista *lista){
    lista->ref = NULL;
    lista->fim = NULL;
}

// procedimento para inserir no in�cio
void inserir_no_inicio(Lista *lista, int num){
    Celula *novo = malloc(sizeof(Celula));

    if(novo){
        novo->info = num;
        novo->prox = lista->ref;
        lista->ref = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(Lista lista){
	Celula *p = lista.ref;
	if(p!=NULL){
		printf("%d ",p->info);
		p = p->prox;
	}else{
		printf("\nLista Vazia\n");
	}
	printf("\n\n");
}

/* void Troca(struct lista *L, struct no *P) ou */
void troca(Lista *plista, Celula *p){
	 Celula *ante;
	 Celula *prox = p->prox;
	 
	 if(prox == NULL){
	 	return; /* imposs�vel trocar posi��es. */
		 } 
	 ante = plista->ref;
	 while(ante->prox != p){
	 	ante = ante->prox;
	 }
 /* ante � o n� anterior ao n� P */
	 ante->prox = prox;
	 p->prox = prox->prox;
	 prox->prox = p;
	 if(plista->fim == prox){
	 	plista->fim = ante; 
		 }
}

int main(){

	return 0;
}

