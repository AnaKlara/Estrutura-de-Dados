/*Merge-Sort*/

#include <stdio.h>
#include <stdlib.h>

main(){
		int x[TAM], i;
		
		for(i=0; i<TAM; i++){
			scanf("%d", &x[i]);
			}
		merge(x, 0 TAM-1);
		
		for(i=0; i<TAM; i++){
			printf("\n x[%d]=%d", i, x[i]);
			}		
	
}

void merge(int x[], int inic, int fim){
	int meio, i;
	
	if(inic<fim){
		meio = (int)(inic+fim)/2;
		merge(x, inic, meio);
		merge(x, meio+1, fim);
		intercala(x, inic, meio, fim);
		}	
}

void intercala(int x[], int inic, int meio, int fim){
	int pos, v1, v2, i; 
	int aux[TAM];
	
	v1 = inic;
	v2 = meio+1;
	
	pos = inic;
	while(v1 <= meio && v2<=fim){
		if(x[v1] <= x[v2]){
			aux[pos] = x[v1];
			v1++;
			}
		else {
			aux[pos] = x[v2];
			v2++;
			}
		pos++;
		
		//Se ainda exixtirem numeros no 1º vetor
		for(i=v2; i<=fim; i++){
			aux[pos] = x[i];
			pos++;
			}
			
		//retorna os valores de aux para o valor x
		for(i=inic; i<=fim; i++){
			x[i] = aux[i];
			}	
		}
	}
