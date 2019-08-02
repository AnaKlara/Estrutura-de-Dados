/* Árvore binária 05/09 */

#include <stdio.h>
#include <stdlib.h>

typedef int tno; //util?

typedef struct_tnoe{
	int chave;
	struct _tnoe *esq, *dir;
	
	}tnoe;
	
tnoe * cria_no (tno chave){
	
	tnoe *no;
	
	no = (tnoe *)malloc(sizeof(tnoe));
	if(no == NULL) exit(0);
	
	no->chave = chave;
	no->esq = NULL;
	no->dir = NULL;
	return no;	
	}

void cria_vazia(tnoe **arv){
	*arrv = NULL;
	return;
	}

int arvore_vazia(tnoe *arv){
	return (arv == NULL);
	}	

int inserir(tnoe **arv, int valor){
	tnoe *aux, *aux2;
	
	aux = cria_no(valor);
	
	if(arvore_vazia(*arv)){ 
		*arv = aux;
	}	
	else {
		aux2 = *arv;
		if(valor == aux2->chave){
			return -1; //valor já existente
			}
		if(valor > aux2->chave){
			if(aux2->dir == NULL){
				aux2->dir = aux;	
				}
			else {
				aux2 = aux2->dir;
				inserir(&aux2, valor);
				}
			}
		else{//vai entrar na subárvore à esquerda;
			if(aux2->esq == NULL){//vai inserir aqui
				aux2->esq = aux;
				}
			else{//vai continuar procurando uma folha
				aux2 = aux2->esq;
				inserir(&aux2, valor);
			}	
		}
	}
return 1;
}

void percorrer(tnoe *arv){
	if(arvore_vazia(arv)){
		printf("\n Vazia");
		return;
		}
	else{
		printf("\nChave = %d, arv->chave");
		percorrer(arv->dir);
		percorrer(arv->esq);
	}
	
	
