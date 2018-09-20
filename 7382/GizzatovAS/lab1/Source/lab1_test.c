#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 100

int br_check(char* str,int cur,int k){
	//cur=0;
	char* ptr;
	if(strcmp(str,"(BAA)") == 0){
		return 1;
	}
	if(cur>strlen(str)){
		return 0;
	}
	if(strcmp(str,"A") == 0){
		return 1;
	}
	if(str[cur] == '(' && str[cur+1] == 'B' && str[cur+2] == 'A' && str[cur+3] == 'A' && str[cur+4] == ')'){			
		str[cur] = 'A';											//deleting unnecessary symbols
		ptr = str+cur+5;										// and replacing them with single 'A'
		str[cur+1]='\0';
		strcat(str,ptr);
		for(int i=0;i<k;i++)
			printf("\t");
		printf("Глубина рекурсии:%d\n",k);
		for(int i=0;i<k;i++)
                        printf("\t");

		printf("Текст после выполнения алгоритма:%s\n",str);
		br_check(str,cur-2,k+1);									//call recursion with 
	}
	else{
		br_check(str,cur+1,k);
	}
}

void no_tabs(char* str){
	char* cur_ptr;
	for(int i=0;i<strlen(str);i++){
		if(isspace(str[i])){										//deleting all tabulations and spaces
			cur_ptr = str+i+1;
			str[i]= '\0';
			strcat(str,cur_ptr);
			i--;
		}
	}
}




int main(){
        char *brackets = (char*)calloc(N,sizeof(char));
        fgets(brackets,N,stdin);										//reading the brackets
        brackets[strlen(brackets)-1]='\0';
        no_tabs(brackets);   //deleting all the spaces and tabulations
	printf("Текст после удаления всех пробелов и табуляций:%s\n",brackets);
	printf("Вывод изменения текста после выполнения каждого шага рекурсии:\n");
        if(br_check(brackets,0,0)){
                printf("Результат-текст является скобками\n");
        }
        else{
                printf("Результат-текст не является скобками\n");
        }
	free(brackets);
        return 0;
}

