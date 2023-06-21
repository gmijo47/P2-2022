/*Napisati program koji definira strukturu za zapis podataka o automobilima: proizvoðaè
(string), model (string), snaga motora (int) i cijena (float). Dinamièki se alocira memorija 
za niz od 10 automobila i unose se podaci o automobilima, te se sortiraju po 
proizvoðaèu, odnosno modelu (ako je proizvoðaè isti). Unosi se dodatni realan broj i 
ispisuju podaci o automobilima èija je cijena manja od dodatnog broja. Koristiti 
iskljuèivo sintaksu pokazivaèa. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 5
struct c{
	char p[32];
	char m[32];
	int sm;
	float cj;
};

void main() {
	
	struct c *arr, *p;
	float *d;
	int i, j;
	
	arr = (struct c*) malloc(sizeof(struct c)*num);
	p = (struct c*) malloc(sizeof(struct c));
	d = (float *) malloc(sizeof(float));
	
	
	for(i = 0; i< num; i++){
		puts("Unesi proizvodaca");
		fflush(stdin);
		gets((arr+i)->p);
		puts("Unesi model");
		fflush(stdin);
		gets((arr+i)->m);
		puts("Unesi snagu motora:");
		scanf("%d", &((arr+i)->sm));
		puts("Unesi cijenu:");
		scanf("%f", &((arr+i)->cj));
		puts("__________\n");
	}
	
	puts("Unesi kriteriji cjene");
	scanf("%f", d);
	
		for(i = 0; i < num-1; i++){
		for(j = i+1; j < num; j++){
			

			if(stricmp((arr+i)->p, (arr+j)->p) > 0){
				
				*p = arr[i];
				arr[i] = arr[j];
				arr[j] = *p;
				
			}else if(stricmp((arr+i)->p, (arr+j)->p) == 0){
				if(stricmp((arr+i)->m, (arr+j)->m) > 0){
				
				*p = arr[i];
				arr[i] = arr[j];
				arr[j] = *p;
				
				}	
			}
			
		}
	}
	
	puts("\nAutomobili u kriteriju su:");
	for(i = 0; i < num; i++){
		
		if((arr+i)->cj < *d){
		
			puts((arr+i)->p);
			puts((arr+i)->m);
			printf("%d\n", (arr+i)->sm);
			printf("%.2f\n", (arr+i)->cj);
			puts("\n");
		}
		
	}

	free(arr);
	free(p);
	free(d);


}
