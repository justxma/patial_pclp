#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int f1(char **addr_p){
	int *upper = 0;
	int *lower = 0;
	int size = 0;
	int capacity = 10; // consideram pentru toate sirurile aceeasi lungime
	int lowCap = 10;
	int upCap = 10;
	int count_mari = 0;
	int count_mici = 0; 
	*addr_p = (int *)calloc(capacity , sizeof(char));
	if(*addr_p == NULL){
		printf("Eroare la alocarea memoriein\n");
		return -1;
	}
	upper = (char *)calloc(capacity , sizeof(char));
	lower = (char *)calloc(capacity , sizeof(char));
	char litera;
	while(scanf("%c" , &litera) == 1){
		if(litera == '\n'){
			break;
		}
		if(size == capacity){
			int *temp ;
			capacity *=2;
			temp = (char *)realloc(*addr_p , capacity * sizeof(char));
			if(temp == NULL){
				printf("Eroare la realocarea memoriei\n");
				return -1;
			}else{
				*addr_p = temp;
				// free(temp);
			}
		}
		if(count_mici == lowCap){
			int *lowTemp;
			lowCap *=2;
			lowTemp = (char *)realloc(lower , lowCap * sizeof(char));
			if(lowTemp == NULL){
				printf("Eroare la realocarea memoriei\n");
				return -1;
			}else{
				lower = lowTemp;
			}
		}
		if(islower(litera)){
			lower[count_mici++] = litera;
		}


		if(count_mari == upCap){
			int *upTemp;
			upCap *= 2;
			upTemp = (char *)realloc(upper , upCap * sizeof(char));
			if(upTemp == NULL){
				printf("Eroare la realocarea memoriei\n");
				return -1;
			}
		}
		if(isupper(litera)){
			upper[count_mari++] = litera;
		}
		*(addr_p)[size++] = litera;
	}
	//end while


	for(int i = 0 ;i  < count_mari - 1; i++){
		for(int j = i + 1 ; j < count_mari ; j++){
			if(upper[i] > upper[j]){
				int aux = upper[i];
				upper[i] = upper[j];
				upper[j] = aux;
			}
		}
	}
	for(int i = 0 ; i < count_mici  -1; i++){
		for(int j = i + 1 ; j < count_mici ; j++){
			if(lower[i] > lower[j]){
				int aux = lower[i];
				lower[i] = lower[j];
				lower[j] = aux ;
			}
		}
	}




	return abs(count_mari - count_mici);
}

int main(void){
	char *sir;
	int *p = &sir;
	int k = f1(&p);
	printf("%d" , k);
	return 0;
}