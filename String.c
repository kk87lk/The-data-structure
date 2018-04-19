#include <stdio.h>
#include <stdlib.h>
#define Maxsize 5
typedef int Vertex;
typedef struct string{
    char data[Maxsize];
    int len;
}String;
int Getlen(char *s){
    int i = 0;
    while(s[i]!='\0'&&i<Maxsize){
        i++;
    }
    return i;
}
String* Create(){
    int i;
    String *S=(String*)malloc(sizeof(String));
    S->len = 0;
    for (i = 0; i < S->len; i++)
    {
        S->data[i] = '0';
    }

    return S;
}
String* Assign(String* S,char s[]){
    int i = 0;
    for (i = 0; i < Getlen(s) ;i++){
        S->data[i] = s[i];
    }
    S->len = Getlen(s);
    return S;
}
void printString(String* S){
    int i = 0;
    while(i<S->len&&i<Maxsize)
        printf("%c", S->data[i++]);
}
int Insert(String *S, Vertex pos,String* Q){
    int i,k;
    if(pos<1||pos>S->len+1)
        return 0;
    else if(S->len + Q->len <= Maxsize)
    {
        for (i = S->len - 1; i >=pos-1; i--)
        {
            S->data[i + Q->len] = S->data[i];
        }
        for (k = 0; k < Q->len;){
            S->data[++i] = Q->data[k++];
        }
        S->len += Q->len;
    }else if(pos+Q->len<Maxsize+1){
        for (i = Maxsize - 1; i >= S->len - pos;i--)
        {
            S->data[i + Q->len] = S->data[i];
        }
        for (k = 0; k < Q->len;)
        {
            S->data[++i] = Q->data[k++];
        }
        S->len = Maxsize;
    }else{
        for (i = 0; i <=Maxsize-pos;i++){
            S->data[i+pos-1] = Q->data[i];
        }
        S->len = Maxsize;
    }
    return 1;
}
String* Delete(String* S,Vertex pos,int len){
    int i;
    if(pos<1||pos+len>S->len+1)
        return 0;
    for (i = pos + len - 1; i < S->len;i++)
        S->data[i - len] = S->data[i];
    S->len -= len;
    return S;
}
String* Copy(String* S1,String* S2){
    int i;
    for (i = 0; i < S2->len;i++){
        S1->data[i] = S2->data[i];
    }
    S1->len = S2->len;
    return S1;
}
int isempty(String *S){
    return (S->len == 0);
}
int Compare(String* S1,String* S2){                                             //若存在溢出，则不考虑溢出的长度。
    int i;
    for (i = 0; i < S1->len && i < S2->len;i++){
        if(S1->data[i]!=S2->data[i])
            return (S1->data[i] - S2->data[i]);
    }
    return (S1->len - S2->len);
}
int GetStringlen(String* S){
    return (S->len);
}
int Clear(String* S){
    S->len = 0;
    int i = 0;
    for (i = 0; i < S->len;i++){
        S->data[i] = '0';
    }
    return 1;
}
String* CatString(String* S1,String* S2){
    int i = 0;
    if(S1->len+S2->len<=Maxsize){
        for (i = S1->len; i < S1->len + S2->len;i++){
            S1->data[i] = S2->data[i - S1->len];
        }
        S1->len += S2->len;
    }else if(S1->len<Maxsize){
        for (i = S1->len; i < Maxsize;i++){
            S1->data[i] = S2->data[i - S1->len];
        }
        S1->len = Maxsize;
    }else{
        return S1;
    }
    return S1;
}
String* SubString(String* S,Vertex pos,int len,String* Sub){
    int i = 0;
    if(pos<1||pos>S->len||len<1||len+pos>S->len+1){
        Sub->len = 0;
        return 0;
    }else{
        for (i = 0; i<len;i++){
            Sub->data[i] = S->data[i + pos-1];
        }
        Sub->len = len;
    }
    return Sub;
}
int FindSubString(String* S,String* Q,Vertex pos){
    int i = pos;
    int j = 0;
    if(!Q->len||!pos)
        return 0;
    while (i<S->len&&j<Q->len)
    {
        if(S->data[i]==Q->data[j]){
            i++;
            j++;
        }else{
            i=i-j+1;
            j = 0;
        }
    }
    if(j>=Q->len)
        return (i - j+1);
    else
        return -1;
}
String* Replace(String* S,Vertex pos,String* Q,String* T){          //S原串 Q被替换串 T替换串
    int i = 0;
    if(Q->len==T->len){
        for (i = pos - 1; i < T->len+pos-1;i++){
            S->data[i] = T->data[i - pos + 1];
        }
        S->len = S->len + (T->len - Q->len);
        //return S;
    }else if(Q->len>T->len){
        for (i = Q->len + pos - 1; i <S->len ; i++){
            S->data[i - 1] = S->data[i];
        }
        for (i = pos - 1; i < T->len + pos - 1; i++)
        {
            S->data[i] = T->data[i - pos + 1];
        }
        S->len = S->len + (T->len - Q->len);
        //return S;
    }else if(Q->len<T->len){
        if(S->len-Q->len+T->len<=Maxsize){
            for (i = S->len - 1; i >= pos + Q->len - 1;i--){
                S->data[i + T->len-1] = S->data[i];
            }
            for (i = pos - 1; i < T->len + pos - 1; i++)
            {
                S->data[i] = T->data[i - pos + 1];
            }
            S->len = S->len + (T->len - Q->len);
            //return S;
        }
        else if ((S->len - Q->len + T->len > Maxsize)&&(pos+T->len<=Maxsize+1)){
            for (i = pos - 1; i < pos + T->len-1;i++){
                S->data[i] = T->data[i - pos + 1];
            }
            S->len = S->len + (T->len - Q->len);
            //return S;
        }
        else{
            for (i = pos - 1; i < Maxsize; i++)
            {
                S->data[i] = T->data[i - pos + 1];
            }
            S->len = S->len + (T->len - Q->len);
            //return S;
        }
    }
    return S;
}
    int main(){
        String *S = Create();
        String *S2 = Create();
        String *S3 = Create();
        char s[100],s2[100],s3[100];
        gets(s);
        gets(s2);
        gets(s3);
        Assign(S,s);
        Assign(S2, s2);
        Assign(S3, s3);
        // Insert(S, 2, S2);
        // printString(S);
        // printf("\n");
        // Delete(S, 2, 3);
        // printString(S);
        // SubString(S, 1, 4, S3);
        // printString(S3);
        //Copy(S, S2);
        //CatString(S, S2);
        //printString(S);
        //printf("%d", Compare(S, S2));
        //printf("%d", FindSubString(S, S2, 1));
        Replace(S, 2, S2, S3);
        printString(S);
    }
