#include <stdio.h>
#include <string.h>

void main() {
	
	char str[256];
	int i, br[256];
	
	gets(str);
	for(i=0; i < strlen(str); i++){

		br[i] = (int) str[i];
		printf("%d\n", br[i]);
		
	}	
	
}
