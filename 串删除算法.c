#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 50
typedef struct string
{
    char data[Maxsize];
    int len;
} String;
void StrDelete(String* S,int i,int m){
    int len = strlen(S->data);
    char *temp = (char *)malloc(len * sizeof(char));
    int j = 0,k=0;
    if(i<0||i>=len||m==0)  return;
    if(i+m>=len){
        for (j = 0,k=0; j < i;j++,k++){
            temp[k] = S->data[j];
        }
        strcpy(S->data, temp);
        S->len=i;
    }else{
        for (j = 0,k=0; j < i;j++,k++){
            temp[k] = S->data[j];
        }
        for (j = i + m ; j < len;j++,k++){
            temp[k] = S->data[j];
        }
        strcpy(S->data, temp);
        S->len -= m;
    }
    
}

int main(){
    String *S=(String*)malloc(sizeof(String));
   	strcpy(S->data,"abcdefg");
   	S->len=7;
    StrDelete(S, 5, 8);
    int i=0;
	for(i=0;i<S->len;i++){
		printf("%c",S->data[i]);
	}
}
