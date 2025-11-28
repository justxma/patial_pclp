#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int f1(char **addr_p){
	char *upper = NULL;
	char *lower = NULL;
	int size = 0;
	int capacity = 10; // consideram pentru toate sirurile aceeasi lungime
	int lowCap = 10;
	int upCap = 10;
	int count_mari = 0;
	int count_mici = 0; 
	*addr_p = (char *)calloc(capacity , sizeof(char));
	upper = (char *)calloc(capacity , sizeof(char));
	lower = (char *)calloc(capacity , sizeof(char));
	if(*addr_p == NULL || upper == NULL || lower == NULL){
		printf("Eroare la alocarea memoriei\n");
		free(*addr_p);
		free(lower);
		free(upper);
		return -1;
	}
	char litera;

	while(scanf("%c" , &litera) == 1){
		if(litera == '\n'){
			break;
		}
		if(size == capacity){
			char *temp ;
			capacity *=2;
			temp = (char *)realloc(*addr_p , capacity * sizeof(char));
			if(temp == NULL){
				printf("Eroare la realocarea memoriei\n");
				free(*addr_p);
				*addr_p = NULL;
				free(upper);
				free(lower);
				return -1;
			}
			*addr_p = temp;		
		}
		(*addr_p)[size++] = litera;



		if(count_mici == lowCap){
			char *lowTemp;
			lowCap *=2;
			lowTemp = (char *)realloc(lower , lowCap * sizeof(char));
			if(lowTemp == NULL){
				printf("Eroare la realocarea memoriei\n");
				free(*addr_p);
				*addr_p = NULL;
				free(upper);
				free(lower);
				return -1;
			}else{
				lower = lowTemp;
			}
		}
		if(islower(litera)){
			lower[count_mici++] = litera;
		}


		if(count_mari == upCap){
			char *upTemp;
			upCap *= 2;
			upTemp = (char *)realloc(upper , upCap * sizeof(char));
			if(upTemp == NULL){
				printf("Eroare la realocarea memoriei\n");
				free(*addr_p);
				*addr_p = NULL;
				free(upper);
				free(lower);
			}
		}
		if(isupper(litera)){
			upper[count_mari++] = litera;
		}
	}
	//end while


	//sortare upper
	for(int i = 0 ;i  < count_mari - 1; i++){
		for(int j = i + 1 ; j < count_mari ; j++){
			if(upper[i] > upper[j]){
				char aux = upper[i];
				upper[i] = upper[j];
				upper[j] = aux;
			}
		}
	}

	//sortare lower
	for(int i = 0 ; i < count_mici - 1; i++){
		for(int j = i + 1 ; j < count_mici ; j++){
			if(lower[i] > lower[j]){
				char aux = lower[i];
				lower[i] = lower[j];
				lower[j] = aux ;
			}
		}
	}
	int index_mare = 0;
	int index_mic = 0;
	for(int i = 0 ; i < size ; i++){
		if(isupper((*addr_p)[i])){
			if(index_mare < count_mari){
				(*addr_p)[i] = upper[index_mare++];
			}
		}else if(islower((*addr_p)[i])){
			if(index_mic < count_mici){
				(*addr_p)[i] = lower[index_mic++];
			}
		}
	}
	free(upper);
	free(lower);
	return abs(count_mari - count_mici);
}

int main(void){
	char *sir = NULL;
	int k = f1(&sir);
	if(k != -1 && sir != NULL){
		printf("Sirul modificat este : %s\n" , sir);
		free(sir);
	}
	printf("Diferenta in modul dintre literele mari si literele mici: %d\n" , k);
	return 0;
}