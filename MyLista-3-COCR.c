//manipula Lista COM Ordenação & COM Repetição

#include <stdio.h>
#include <stdlib.h>
#define TAM 5


/* Características de uma lista:
 -os elementos podem ser inseridos e removidos de qualquer posição da estrutura;
 -não existe um marcador de início ou fim, para saber se a lista esta cheia ou vazia. Então, usaremos um contador para controlar o espaço ocupado na lista;
 -iremos inserir sempre no fim da lista;
 * 
 * 
 -As remoções podem ocorrer em qualquer lugar, então a cada remoção colocaremos o ultimo elemento no lugar do que saiu;
 *
 *
 */

typedef struct{//com typedef cria-se um novo tipo de variável 
	int vetor[TAM];
	int cont;

}conteiner;

void seleciona();
void cria_lista();
int lista_vazia(); 
int lista_cheia();
void inserir(); 
void remover();
void percorrer();
void ordenar();

int main(){
	int option, sair;
	conteiner lista; 	
	conteiner *ptr;
	ptr = &lista;
	
	printf("\nBem Vindo ao manipulador de lista!\nCOM ordenação e COM repetição de Valores!\n\n");	
	
	while(sair == 0){
	
		seleciona();
		scanf("%d",&option);
	
			switch(option){
			
			case 1 :
				cria_lista(ptr);
				break;
				
			case 2://A lista está vazia?
				lista_vazia(lista);
				break;
				
			case 3://A lista está cheia?
				lista_cheia(lista);
				break; 
				
			case 4:
				inserir(ptr, lista);
				break;
				
			case 5:
				remover(ptr, lista);
				break;
				
			case 6 :
				percorrer(lista);
				break;
			
			case 7:
				ordenar(ptr);
				break;
				
			case 8:
				printf("\nTchau! Volte sempre!\n");
				sair = 1;
				break;
				
		};
	};
	return 0;
};

void seleciona(){
	printf("\nDigite a opção de sua preferência: \n");	
	printf("\nDigite (1) para criar lista");
	printf("\nDigite (2) para verificar se a lista está vazia");
	printf("\nDigite (3) para verificar se a lista está cheia");
	printf("\nDigite (4) para inserir elemento");
	printf("\nDigite (5) para remover elemento");
	printf("\nDigite (6) para percorrer o vetor");
	printf("\nDigite (7) para ordenar o vetor");
	printf("\nDigite (8) para sair\n\n");
	};

void cria_lista(conteiner *ponteiro){ 
		ponteiro->cont = 0;//esta operação está aqui pq não podemos inicializar valores dentro de uma struct
		printf("\nLista inicializada com sucesso!\n ");
	};

int lista_vazia(conteiner x){ 
	if(x.cont==0){
		printf("\nA lista está vazia!\n");
		return 1;	
		}
	else {
		printf("\nA lista não está vazia!\n");
		return 0;	
		}	
};

int lista_cheia(conteiner z){ 
	if(z.cont==TAM){
		printf("\nA lista está cheia!\n");
		return 1;	
		}
	else{
		printf("\nA lista não está cheia!\n");
		return 0;	
		}
};

int inserir(conteiner *ponteiro, conteiner t){ 
	int gandula;
	if(lista_cheia(t)){
		printf("\nNão é possível inserir mais elementos!\n");
		}
	else{		
		printf("\n Qual valor vc deseja inserir?\t");
		scanf("%d",&gandula);
		ponteiro->vetor[ponteiro->cont]=gandula;
		ponteiro->cont++;
	};
};	
	
void remover(conteiner *ponteiro, conteiner x){	
	int gandula;
	int resultado = -1;
	
	if(lista_vazia(x)){ 
		printf("\n A lista precisa conter elementos pra possam ser removidos!\n");
		}
	else{
		printf("\n Qual elemento você gostaria de remover?\t");
		scanf("%d",&gandula);
		for(int i; i<ponteiro->cont; i++){
			if(ponteiro->vetor[i]==gandula) 
				resultado = i;
			};	
		if(resultado==-1){
			printf("\n O elemento requisitado não existe!");
			}/*--------------------------------------------------AQUIIII----------------------------------*/
		else{	//aqui o vetor do elemento a ser removido receberá o conteúdo do último vetor para tampar o buraco
		ponteiro->vetor[resultado]=ponteiro->vetor[ponteiro->cont-1];
		ponteiro->cont--;// Aqui o contador de conteúdo é atualizado 
			printf("\nElemento removido com sucesso!\n");
			}
		}	
};



void percorrer(conteiner v){//só para mostrar todos os elemntos da fila
	if(lista_vazia(v)){
		printf("\n Não há como percorrer uma lista vazia uai!\n");
		}
	else{	
		printf("\n");
		printf("\nPrintando de acordo com contador\n");
		for(int i=0; i<v.cont; i++){
			printf("%d\t", v.vetor[i]);
			};
		printf("\nPrintando de acordo com o índice do vetor\n");
		for(int i=0; i<TAM-1; i++){
			printf("%d\t", v.vetor[i]);
			};
		printf("\nPrintando de acordo com o índice do vetor\n");		
	}
};

void ordenar(conteiner *ponteiro){//Selection Sort
		int i, j, min, aux;
		  for (i = 0; i < (TAM-1); i++) {
			 min = i;
			 for (j = (i+1); j < TAM; j++) {
			   if(ponteiro->vetor[j] < ponteiro->vetor[min]) 
				 min = j;
				};
			 if (i != min) {
			   aux = ponteiro->vetor[i];
			   ponteiro->vetor[i] = ponteiro->vetor[min];
			   ponteiro->vetor[min] = aux;
			 };
		  };
	printf("\nLista ordenada com sucesso!\n");
	};
