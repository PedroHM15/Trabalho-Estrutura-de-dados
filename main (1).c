#include <stdio.h>
#include <stdlib.h>
struct lista {
	int info;
	struct lista *prox;
};
typedef struct lista
Lista;

Lista* criaLista(){
 return NULL;
};

Lista* inserirLista(Lista *lista, int i){
 Lista* novo = (Lista*) malloc(sizeof(Lista));
 novo -> info = i;
 novo -> prox = lista;
 return novo;
};

Lista *imprimeLista(Lista *l) {
 Lista *p;
 for (p = l; p != NULL; p = p->prox) {
 printf("%d\n", p->info);
 }
}

int listaVazia(Lista *l){
 if(l == NULL){
 return 1;
 }else{
 return 0;
 }
}

Lista *buscaLista(Lista *l, int v){
 Lista *p;
 for(p = l; p != NULL; p = p->prox){
 if(p->info == v){
 return p;
 }
 }
 return NULL;
}

Lista *retiraLista(Lista *l, int v){
 //ponteiro para elemento anterior
 Lista *ant = NULL;
 //ponteiro para percorrer a lista
 Lista *p = l;
 //procura elemento na lista, guardando anterior
 while(p != NULL && p->info != v){
 ant = p;
 p = p->prox;
 }
 //verifica se achou elemento
 if(p == NULL){
 //não achou: retorna lista original
 return l;
 }
 //retira elemento
 if(ant == NULL){
 //retira elemento do inicio
 l = p->prox;
 }else{
 //retira elemento do meio da lista
 ant->prox = p->prox;
 }
 free(p);
 return l;
}

void liberaLista(Lista *l){
 Lista *p = l;
 while(p != NULL){
 //guarda referência para o próximo elemento
 Lista *t = p->prox;
 free(p); //libera a memória apontada por p
 p = t; //faz p apontar para o próximo
 }
}
Lista* inserirListaOrden(Lista *l, int i) {
    Lista *p, *ant = NULL;
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->info = i;

    // Procura a posição correta para inserir
    for (p = l; p != NULL && p->info < i; p = p->prox) {
        ant = p;
    }

    // Insere no início da lista
    if (ant == NULL) {
        novo->prox = l;
        return novo;
    } 
    // Insere no meio ou no final
    else {
        novo->prox = ant->prox;
        ant->prox = novo;
        return l;
    }
}





int main(){
 Lista* l;
 int x=1;
 int y;
    while(x!=0){
        printf("1 - Para cadastrar um novo numero\n2 - Imprimir a lista\n3 - Esvaziar a lista\n4 - Buscar um numero na lista\n5 - Retirar um numero da lista\n6 - Inserir um numero em ordem\n0 - Para Sair\n");
        scanf("%d", &x);
        switch (x){
            case 1:
                printf("Informe o numero que deseja inserir: ");
                scanf("%d", &y);
                l = inserirLista(l, y);
                break;

            case 2:
                printf("Lista:\n");
                imprimeLista(l);
                break;

            case 3:
                liberaLista(l);
                l = criaLista();
                printf("Lista esvaziada.\n");
                break;

            case 4:
                printf("Informe o numero que deseja buscar: ");
                scanf("%d", &y);
                if (buscaLista(l, y) != NULL) {
                    printf("Numero %d encontrado na lista.\n", y);
                } else {
                    printf("Numero %d nao encontrado.\n", y);
                }
                break;

            case 5:
                printf("Informe o numero que deseja retirar: ");
                scanf("%d", &y);
                l = retiraLista(l, y);
                printf("Numero %d retirado da lista se existia.\n", y);
                break;

            case 6:
                printf("Informe o numero que deseja inserir em ordem: ");
                scanf("%d", &y);
                l = inserirListaOrden(l, y);
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;
                
            
            
        }        
    }
 return 0;
};