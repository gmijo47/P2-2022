#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct recenica{
	
	char recenica[128];
	int brr;
	int dulj;
	char nrur[32];
	
};
int clcbrr(char r[]){
	int br = 0, i;
	for(i=0; i < strlen(r); i++){
		
		if(isalpha(r[i])){
			
			if(r[i+1] == ' ' || r[i+1] == '\0'){
				br++;
			}
		}
	}
	
	return br;
}
int lng(char u[]){
	
	int i, len = 0;
	for(i = 0; i < strlen(u); i++){
		
		if(isalpha(u[i])){
			len++;
		}
		
	}
	
	return len;
	
}
void lngst(char r[], char nr[]){
	
	int len_rec = 0, i, len_tmp = 0;
	char rec[32], testwrd[32];
	
	for(i=0; i < strlen(r); i++){
		
		if(isalpha(r[i])){
			
			testwrd[len_tmp] = r[i];
			len_tmp++;
			
			if(r[i+1] == ' ' || r[i+1] == '\0'){
				
				testwrd[len_tmp] = '\0';
				
				if(len_tmp > len_rec){
					
					len_rec = len_tmp;
					strcpy(rec, testwrd);
					
				}
				len_tmp = 0;
			}
		}
	}
	
	strcpy(nr, rec);
	
}
void sort(struct recenica r[], int br){
	int i, j;
	struct recenica pom;
	
	for(i = 0; i< br-1; i++){
		for(j = i+1; j < br; j++){
			
			if(r[i].brr == r[j].brr){
				if(r[i].dulj < r[j].dulj){
					
					pom = r[i];
					r[i] = r[j];
					r[j] = pom;
					
					
				}
			}else {
				if(r[i].brr < r[j].brr){
					
					pom = r[i];
					r[i] = r[j];
					r[j] = pom;
					
					
				}
			}
		}
	}
}
void formstr(struct recenica r[], int brr, char str[]){
	
	int i;
	for(i = 0; i < brr; i++){
		
		strcat(str, r[i].nrur);
		strcat(str, " ");
		
		
	}
	
}
void unos(struct recenica r[], int *br){
	
	char u[128], lng_wrd[32];
	puts("Unesi neku recenicu, za kraj unesi \"kraj\"");
	do{
		
		gets(u);
		if(stricmp(u, "kraj") != 0){
		strcpy(r[*br].recenica, u);
		r[*br].brr = clcbrr(u);
		r[*br].dulj = lng(u);
		lngst(u, lng_wrd);
		strcpy(r[*br].nrur, lng_wrd);
		(*br)++;
		}
		
	}while(stricmp(u, "kraj") != 0);
	
}
void main() {
	
	int num_rec = 0;
	char str[128] = "";
	struct recenica recenice[32] = {0};
	unos(recenice, &num_rec);
	sort(recenice, num_rec);
	formstr(recenice, num_rec, str);
	printf("Recenica je: %s \n", str);
	
	
	
}
