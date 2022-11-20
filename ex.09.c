#include <stdio.h>
#include <stdlib.h>

/*9. Voc� foi contratado pela Google para refazer o Orkut. A sua primeira tarefa �
implementar uma estrutura de dados para representar as rela��es de amizade dentro
do Orkut. Ou seja, para cada pessoa cadastrada voc� tem que armazenar a sua lista
de amigos. Considere que cada pessoa no Orkut tem um identificador �nico que � um
n�mero inteiro.
a. Declare os tipos necess�rios para a implementa��o dessa estrutura.
b. Escreva um procedimento para cadastrar dois amigos:
void Relaciona(int Amigo1, int Amigo2, TipoOrkut* pOrkut) 
Considere que o Amigo1 j� est� cadastrado no Orkut, enquanto o Amigo2 pode ou n�o
j� estar cadastrado.*/

typedef struct{
	char nome[50];
	int id;
}Usuario;

typedef struct tipoOrkut{
	Usuario info;
	struct tipoOrkut *prox;
}TipoOrkut;

TipoOrkut* crialista(){
	return NULL;
}

Usuario cadastra_usuario(Usuario usuario){
	printf("Digite seu nome:\n");
	fflush(stdin);
	gets(usuario.nome);
	printf("Digite o Id:\n");
	scanf("%d",&usuario.id);

	return usuario;
}

// fun��o para inserir no in�cio

TipoOrkut* insere(TipoOrkut *ref, Usuario valor){
	TipoOrkut *novoNo = malloc(sizeof(TipoOrkut));
	novoNo->info=valor;
	novoNo->prox = ref;
	ref= novoNo;
	return ref;
}

// procedimento para inserir no meio
//amigo1 j� est� cadastrado e amigo 2 vai ser inserido na sua lista de amigos
void relaciona(TipoOrkut *ref, Usuario amigo1, Usuario amigo2){
    TipoOrkut *aux, *novo = malloc(sizeof(TipoOrkut));

    if(novo!=NULL){
        novo->info = amigo2;
        // � o primeiro?
        if(ref == NULL){
            novo->prox = NULL;
            ref->prox = novo;
        }
        else{
            aux = ref;
            while(aux->info.id != amigo1.id && aux->prox !=NULL)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}


void imprimir(TipoOrkut *ref){
	TipoOrkut *p;
	if(ref==NULL){
		printf("Lista Vazia");
	}else{
		/*p = ao ponteiro que aponta para o come�o da lista, enquanto ele n�o 
		apontar pra nulo(fim) e pulando para o pr�ximo n�*/
		for(p=ref;p!=NULL;p=p->prox){
			printf("Nome:%s\t Id:%2d\n ",p->info.nome, p->info.id);
		}
	}
}

int main() {
	 int op, resp;
	 Usuario novoUser, cadAmigo;
	 TipoOrkut *ref;
	 
	 do{
	 	printf("\n*****menu*****\n");
	 	printf("Escolha a opcao:\n 1 - Deseja criar uma nova Lista?\n 2 - Quer adicionar um novo amigo � sua lista\n 3- Imprimir\n 4 - Sair");
	 	scanf("\n%d",&resp);
	 
	 	switch (resp){
	 	case 1:
	 		ref=crialista();
	 		novoUser = cadastra_usuario(novoUser);
	 		ref=insere(ref, novoUser);
	 	break;
	 	case 2:
	 		cadAmigo = cadastra_usuario(cadAmigo);
	 		if(cadAmigo.id==novoUser.id){
	 			printf("Esse id ja existe, escolha outro!");
	 		}else{
				relaciona(ref, novoUser, cadAmigo);
			 }
	 	break;
	 	case 3:
	 		imprimir(ref);
	 	break;
	 	default:
	 		if(resp!=4){
	 			printf("opcao invalida");
			 }
	 	break;
		 }
	 }while(resp!=4);
	
	 


	
	return 0;
}
