//manipula Fila

#include <stdio.h>
#include <stdlib.h>
#define TAM 6

/* Características de uma FILA ***********COMUM******* :
 inserções são realizadas em uma extremidade do vetor (no fim), enquanto as remoções são realizadas na outra extremidade (no início).
 política FIFO - First in First out
 */

typedef struct{//com typedef cria-se um novo tipo de variável 
	int primeiro; //fila vazia: p > u
	int ultimo;//fila cheia u = TAM -1
	int vetor[TAM];

}conteiner;

void seleciona();
void cria_fila();
int fila_vazia(); 
int fila_cheia();
void quem(); // só pra mostrar;
void push();//coloca no fim;	
void pop();//tira do início; 

int main(){
	int option, sair=0;
	conteiner fila;
	conteiner *ptr;
	ptr = &fila; 	

	printf("\nBem Vindo ao manipulador de fila!\n Sua fila é de 5 posições!\n");	
	
	while(sair == 0){
	
		seleciona();
		scanf("%d", &option);
	
			switch(option){
			
				case 1 :
					cria_fila(ptr);//apenas atualiza os contadores, se ela for chamada com o vetor com valores guardados eles permanecerão!
					break;
					
				case 2://A fila está vazia?
					fila_vazia(fila);
					break;
					
				case 3://A fila está cheia?
					fila_cheia(fila);
					break; 
					
				case 4://Quais os elementos da fila?
					quem(fila);
					break;
					
				case 5://coloca no fim - enfileirar;
					push(ptr, fila);
					break;
					
				case 6: //tira do início - desenfileirar;
					pop(ptr, fila);
					break;
				
				case 7://zera os valores do vetor e atualiza os contadores!
					printf("Fila reinicializada!\n");
					for(int i =0; i < TAM; i++){
						fila.vetor[i]=0;
						};
					cria_fila(ptr);
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
	printf("\n Digite a opção de sua preferência: \n");	
	printf("\nDigite (1) para criar fila");
	printf("\nDigite (2) para verificar se a fila está vazia");
	printf("\nDigite (3) para verificar se a fila está cheia");
	printf("\nDigite (4) para verificar os elementos da fila.");
	printf("\nDigite (5) para colocar ");
	printf("\nDigite (6) para tirar");
	printf("\nDigite (7) para reinicializar");
	printf("\nDigite (8) para sair\n\n");
	};

void cria_fila(conteiner *ponteiro){ // apenas configura os contadores, se tiver conteúdo prévio eles permanecerão!
		ponteiro -> primeiro = 0;// essas inicialização de valores está aqui pq não pode ser feito dentro de uma struct;s
		ponteiro -> ultimo = -1;
		printf("A fila foi inicializada!");
	};

int fila_vazia(conteiner x){ 
	if (x.primeiro > x.ultimo){
		printf("\nA fila está vazia\n");
		return 1;
		}
	else {
		printf("\nA Fila contém elemento(s)!");
		return 0;
		}	
};

int fila_cheia(conteiner y){ 
	if(y.ultimo == TAM -1){
		printf("\n A Fila está cheia!\n");
		return 1;
		}
	else{
		printf("\n A fila não está cheia!\n");	
		return 0;	
		}
	};

void quem(conteiner w){ // só mostra os elementos que estão no vetor;
	if(fila_vazia(w)){
		printf("\nNão tem como percorrer uma fila vazia uai!\n");
		}
	else{	
		//ATENÇÃO: i = w.primeiro para não printar 0 em caso de um elemento removido!
		for(int i=w.primeiro; i <= w.ultimo; i++){//ATENÇAO, menor ou igual para printar o ultimo elemento tb!
			printf("\n\t\t %d", w.vetor[i]);
			};
	}
};	
	
void push(conteiner *ponteiro, conteiner p){//coloca ;	***********************sem retorno != slide
	int gandula;
	if(fila_cheia(p)==1){/////////////////////////////////////////////////////////////////////////////////////O programa não aloca elemento no limbo!
		printf("\nA fila não está apropriada para a operação!\n");
		}
	else{
		printf("A fila está apropriada para a operação, digite o valor que deseja inserir: \n");
		scanf("%d", &gandula);
		ponteiro->ultimo++;
		ponteiro->vetor[ponteiro->ultimo]=gandula;
		}
};

void pop(conteiner *ponteiro, conteiner r/*, int *gandula */){//tira ***********************sem retorno != slide
	if (fila_vazia(r)==1){
		printf("\nNão foi possível desenfileirar já que não tem nada pra tirar!\n");
		}
	else{
		//poderia ter uma variárvel para receber o valor do elemento desempilhado e ser cuspida da função. EX.:
		//*gadula = ponteiro->vetor[ponteiro->primeiro];
		ponteiro->vetor[ponteiro->primeiro]=0;
		ponteiro->primeiro++;
		}
};

