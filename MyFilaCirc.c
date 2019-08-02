//manipula Fila Circular

#include <stdio.h>
#include <stdlib.h>
#define TAM 5 // o vetor vai de 0 a 4

/* Características de uma FILA ***********Circular********* 
 inserções são realizadas em uma extremidade do vetor (no fim), enquanto as remoções são realizadas na outra extremidade (no início).
 política FIFO - First in First out
 */

typedef struct{//com typedef cria-se um novo tipo de variável 
	int primeiro; 
	int ultimo;
	int vetor[TAM];

}conteiner;

void seleciona();
void cria_fila();
int fila_vazia(); //tanto fila_cheia quanto fila_vazia precisam ser do tipo int para retornarem valores para outras funções que dependem delas;
int fila_cheia();
void quem(); // só pra mostrar os elementos;
void push();//coloca por ultimo	
void pop();//tira o primeiro; 
void reinicializar();

int main(){
	int option, sair=0;
	conteiner fila;
	conteiner *ptr;
	ptr = &fila; 	
	
	printf("\nBem Vindo ao manipulador de fila!\n");	
	
	while(sair == 0){
	
		seleciona();
		scanf("%d", &option);
	
			switch(option){
			
				case 1 :
					cria_fila(ptr);
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
					
				case 5://coloca o ultimo - enfileirar;
					push(ptr, fila);
					break;
					
				case 6: //tira o primeiro - desenfileirar;
					pop(ptr, fila);
					break;
					
				case 7:
					reinicializar(ptr);
				
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
	printf("\nDigite (1) para criar fila");
	printf("\nDigite (2) para verificar se a fila está vazia");
	printf("\nDigite (3) para verificar se a fila está cheia");
	printf("\nDigite (4) para verificar os elementos da fila");
	printf("\nDigite (5) para colocar no fim");
	printf("\nDigite (6) para tirar do início");
	printf("\nDigite (7) para reinicializar a fila");
	printf("\nDigite (8) para sair\n\n");
	};

void cria_fila(conteiner *ponteiro){ 
		//agora primeiro e fim vão apontar para o elemento imediatamente anterior ao primeiro da fila 
		ponteiro->primeiro = ponteiro->ultimo = TAM -1; //essa operação está aqui pq não se pode inicializar valores de uma variável dentro da struct
		printf("A fila CIRCULAR foi inicializada!");
	};

int fila_vazia(conteiner x){ 
	if (x.primeiro == x.ultimo){
		printf("\nA fila está vazia\n");
		return 1;
		}
	else {
		printf("\nA Fila contém elemento(s)\n");
		return 0;
		}	
};

int fila_cheia(conteiner y){ 
	if((y.ultimo%TAM)+1==y.primeiro){
		printf("\n A Fila está cheia!\n");
		return 1;
		}
	else{
		printf("\n A fila não está cheia!\n");
		return 0;	
		}
	};

void quem(conteiner w){ // só mostra os elementos;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////q
	if(fila_vazia(w)){
		printf("\nNão há o que mostrar!\n");
		}
	else{
		printf("\nMostraremos o conteúdo do vetor na ordem da FILA\n");
		for(int i=w.primeiro; i< (w.primeiro%TAM); i = ((w.primeiro+=1)%TAM)){
			printf("\t\a %d", w.vetor[i]);
			
			};
		}     	
	};	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	
void push(conteiner *ponteiro, conteiner k){//coloca no fim;	
	int gandula;
	if(fila_cheia(k)){//operação booleana implícita: se fila_cheia resultar em verdadeiro(true), faça:
		printf("\n A fila não pode receber mais elemntos!");
		}
	else {	
		printf("A fila está apropriada para a operação, digite o valor que deseja inserir: \n");
		scanf("%d", &gandula);
		ponteiro->ultimo = (ponteiro->ultimo +1)%TAM;
		ponteiro->vetor[ponteiro->ultimo]=gandula;
		printf("\n Operação bem sucedida");
	}
};

void pop(conteiner *ponteiro, conteiner s/* \ int *gandula   */){//tira do início 
	if (fila_vazia(*ponteiro)){//operação booleana implícita: se fila_vazia resultar em verdadeiro(true), faça:
		printf("Não há elementos para serem removidos!");
		}
	else{
		//poderia ser acrescentado um ponteiro de uma variável externa a função que receberia o valor do elemento desenfileirado para fora da função. EX.:
		//*gadula = ponteiro->vetor[ponteiro->primeiro];	seguindo das demais operações abaixo->
		ponteiro->vetor[ponteiro->primeiro]=0;
		ponteiro->primeiro = (ponteiro->primeiro+1)%TAM;
		printf("\n Operação bem sucedida");	
		}
};
					
void reinicializar(conteiner *ponteiro){
	for(int i =0; i<TAM; i++){
		ponteiro->vetor[i]=0;
		};
	ponteiro->primeiro = ponteiro->ultimo = TAM -1;
	printf("\nA fila CIRCULAR foi renicializada!\n");	
};
