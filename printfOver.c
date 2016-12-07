#include <stdio.h>
#include <string.h>


int is_nonASCII(char caracter){
	if(caracter<0 || caracter>127) return 1;
	
	return 0;

}

int count_nonASCII(char *str){
	int count = 0;
	int i;
	for(i=0; str[i] != '\0'; i++){
		if(is_nonASCII(str[i])) count++;
	}
	return count/2;
}

int strlenOver(char *str){
	return (int)(strlen(str) - count_nonASCII(str));
}

void printfOver(char *palavra, int espaco, int caracteres, int alinhamento){
	int i;

	int numCaracteres = 0;	
	if(caracteres<= strlenOver(palavra)){
		numCaracteres = caracteres;
		char str = *(palavra);
	}else{
		numCaracteres = strlenOver(palavra);

	}

	if(numCaracteres > espaco) numCaracteres = espaco;
	
  int blank_space = espaco - numCaracteres;
	if(alinhamento == 'l' || alinhamento == 'L' || alinhamento == -1){
		//imprime a palavra
		for(i = 0; i<numCaracteres;i++){
			printf("%c",palavra[i]);
			
			if(is_nonASCII(palavra[i])){
				printf("%c",palavra[i+1]);
				i++;
				numCaracteres++;
			}
		}
		//imprime os espaços em branco
		for(i = 0; i<blank_space;i++){
				printf(" ");
		}
		
	}else{
		for(i = 0; i<blank_space;i++){
			printf(" ");
		}
		for(i = 0; i<numCaracteres;i++){
			printf("%c",palavra[i]);
			
			if(is_nonASCII(palavra[i])){
				printf("%c",palavra[i+1]);
				i++;
				numCaracteres++;
			}
		}


	}

}
