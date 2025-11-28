#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int alocarea_memorie(char **addr_p , int capacity){
	*addr_p = (char *)calloc(capacity , sizeof(char));
	if(*addr_p == NULL){
		return -1;
	}
	return 1;
}

int realocare_memorie(char **p , int *capacity){
	char *temp;
	int old_capacity = *capacity;
	*capacity *=2;
	temp = (char *)realloc(*p , *capacity * sizeof(char));
	if(temp == NULL){
		*capacity = old_capacity;
		return -1; //codul de eroare
	}else{
		*p = temp;
		return 1; //realocarea a fost executata cu succes
	}
}

int compare(const void *a , const void *b){
	return *(char *)a - *(char *)b;
}

void rearrenge_string(char *sir , char *litere_mari , char *litere_mici  , int size , int size_mare , int size_mici){	
	
	int index_mare = 0;
	int index_mic = 0;

	for(int i = 0 ; i < size ; i++){

		//verificam pentru majuscule

		if(isupper(sir[i])){
			if(index_mare < size_mare){
				sir[i] = litere_mari[index_mare++];
			}
		}else if(islower(sir[i])){
			if(index_mic < size_mici){
				sir[i] = litere_mici[index_mic++];
			}
		}else{
			continue;
		}
	}
}

int main(){
	char *sir = NULL;
	int size = 0; // lungimea curenta a sirului
	int size_mare = 0; // lungimea curenta a sirului litere_mari
	int size_mici = 0; // lungimea curenta a sirului litere_mici
	int capacity = 10; //capacitatea sirului
	int capacity_mare = 5;
	int capacity_mici = 5;
	char litera;
	char *litere_mari;
	char *litere_mici;
	if(alocarea_memorie(&sir , capacity) == -1){
		printf("Eroare la alocarea memorie\n");
		return -1;
	}
	if(alocarea_memorie(&litere_mari, capacity) == -1){
		printf("Eroare la alocarea memorie\n");
		return -1;
	}
	if(alocarea_memorie(&litere_mici, capacity) == -1){
		printf("Eroare la alocarea memorie\n");
		return -1;
	}
	while(scanf("%c" , &litera) == 1){
		if(litera == '\n'){
			break;
		}


		if(size_mici + 1 >= capacity_mici){
			if(realocare_memorie(&litere_mici , &capacity_mici) == -1){
				printf("Eroare la alocarea memorie\n");
				return -1;
			}
		}	
		if(islower(litera)){
			litere_mici[size_mici++] = litera;
			litere_mici[size_mici] = '\0';
		}


		if(size_mare + 1 >= capacity_mare){
			if(realocare_memorie(&litere_mari , &capacity_mare) == -1){
				printf("Eroare la alocarea memorie\n");
				return -1;
			}
		}
		if(isupper(litera)){
			litere_mari[size_mare++] = litera;
			litere_mari[size_mare] = '\0';
		}

		if(size + 1 >= capacity){
			if(realocare_memorie(&sir , &capacity) == -1){
				printf("Eroare la alocarea memorie\n");
				return -1;
			}
		}
		sir[size++] = litera;
		sir[size] = '\0';
	}
	qsort(litere_mari , size_mare , sizeof(char) , compare);
	qsort(litere_mici , size_mici , sizeof(char) , compare);
	printf("_________________________________________________________________________________\n");
	printf("De la tastatura a fost citit sirul(nesortat) : \n\n%s\n\nSirul este de lungime : %d\n" , sir , size);
	printf("De asemenea acestea sunt 2 subisiruri care contin toate literele mari si mici din subir(cele 2 subsiruri sunt deja sortate)\nLiterele mari : %s\nLiterele mici : %s\n" , litere_mari,litere_mici);
	printf("Sirul nesortat: %s\n" , sir);
	rearrenge_string(sir , litere_mari , litere_mici , size , size_mare , size_mici);
	printf("Sirul  sortat : %s\n" , sir);
	free(litere_mari);
	free(litere_mici);
	free(sir);
	return 0;
}


//dorim sa rearanjam literele in oridine alfabetica , atat celele mari cat si cele mici , cu conditia 
//literele mari sa ramana pe aceelasi pozitii