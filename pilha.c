//manipula pilha

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

/* Características de uma pilha:
 -Inserções e remoções somente pelo topo 1 elemento por vez;
 -O único elemento visível da pilha é o do topo 
 -Topo pode ser um contador que indica em que posição do vetor encontra-se o último elemento da pilha
 */

typedef struct{//com typedef cria-se um novo tipo de variável com tipo de variável mãe struct 
	int topo;
	int vetor[TAM];
}conteiner; // CONTEINER = modelagem de variável do tipo struct 

void seleciona();
void cria_pilha();
int pilha_vazia(); 
int pilha_cheia();
void quem_topo(); // só pra mostrar;
void push();//empilha;	
void pop();//desempilha; 

int main(){
	int option, sair;
	conteiner *ptr;
	conteiner pilha; //ponteiro para var do tipo struct modelada como conteiner;	
	ptr= &pilha;
	//ponteiro recebe o endereço do conteúdo da var pilha de modelagem conteiner do tipo struct;
	
	printf("\nBem Vindo ao manipulador de pilha!\n");	
		
	while(sair == 0){
	
		seleciona();
		scanf("%d",&option);
	
			switch(option){
			
			case 1 :
				cria_pilha(ptr);
				break;
				
			case 2://A pilha está vazia?
				pilha_vazia(pilha);
				break;
				
			case 3://A pilha está cheia?
				pilha_cheia(pilha);
				break; 
				
			case 4://Quem está no topo?
				quem_topo(pilha);
				break;
				
			case 5://empilha
				push(ptr, pilha);
				break;
				
			case 6: //desempilha
				pop(ptr, pilha);
				break;
				
			case 7:
				printf("\n Tchau! Volte sempre!\n");
				sair = 1;
				break;
					
		};
	};
	
	return 0;
};

void seleciona(){
	printf("\n Digite a opção de sua preferência: \n");	
	printf("\nDigite (1) para criar pilha");
	printf("\nDigite (2) para verificar se a pilha está vazia");
	printf("\nDigite (3) para verificar se a pilha está cheia");
	printf("\nDigite (4) para verificar quem está no topo");
	printf("\nDigite (5) para empilhar");
	printf("\nDigite (6) para desempilhar");
	printf("\nDigite (7) para sair\n\n");
	};

void cria_pilha(conteiner *ponteiro){//o operador * retorna o valor no qual seu operando aponta 
		ponteiro->topo = -1; //Topo é um contador que indica em que posição do vetor encontra-se o último elemento da pilha
							//Logo, quando a pilha receber um elemnto, o cont estará na posição 0 (a primeira do vetor).
	};

int pilha_vazia(conteiner x){ //a função apenas vizualisa o conteúdo de uma struct de modelagem conteiner de nome x
	if(x.topo == -1){
		printf("A pilha está vazia!\n");
		return 1;}
	else {
		printf("A pilha não está vazia!\n");
		return 0;}	
};

int pilha_cheia(conteiner e){ //a função apenas vizualisa o conteúdo de uma struct de modelagem conteiner de nome e
	if(e.topo == ((TAM)-1)){
		printf("A pilha está cheia!\n");
		return 1;
		}
	else{ 
		printf("A pilha não está cheia! \n");
		return 0;
		}
};

void quem_topo(conteiner y){ // só mostra o topo
	if(pilha_vazia(y)==1){ //primeiro a func verifica se a pilha está vazia
		printf("\n Preencha a pilha! \n");
		}
	else{//se não estiver vazia, ele printa o conteúdo
		printf("\n O último elemento da pilha é: %d \n", y.vetor[y.topo]);
		}; 
};	
	
void push(conteiner *ponteiro, conteiner w){//empilha;	**************sem retorno != slide
	int gandula;
	if(pilha_cheia(w)==1){//***********************************função pilha cheia recebe como argumento uma struct(pq apenas visualiza) != slide
		printf("\nA pilha não pode ser acrescentada!");
		}
	else{
		printf("A pilha está apropriada para a operação, digite o valor que deseja inserir: \n");
		scanf("%d", &gandula);
		ponteiro->topo++;
		ponteiro->vetor[ponteiro->topo]=gandula;
		};
};

void pop(conteiner *ponteiro, conteiner M/*, int *gandula*/){       //desempilha; *******************************sem retorno != slide
	if( pilha_vazia(M) ){ //***********************************função pilha cheia recebe como argumento uma struct(pq apenas visualiza) != slide
		printf("\n Não há elemento para remover!\n");
		}
	else{
		ponteiro->vetor[ponteiro->topo]=0;
		//ou a função poderia receber um ponteiro de uma variável para cuspir pra fora da função o elemento desempilhado. EX.: 
		// *gandula = ponteiro->vetor[ponteiro->topo];
		ponteiro->topo--;
		printf("Operação realizada com sucesso! \n");
		}
};

/* CUIDADO! as operações de empilhar e desempilhar não podem se confudir!
para empilhar, primeiro andamos para a próxima posição do vetor e guardamos o conteúdo
ao contrário
para desempilhar primeiro alteramos o conteúdo e depois andamos com o vetor! */

