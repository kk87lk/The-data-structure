#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
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
    int i = pos-1;
    int j = 0;
    if(!Q->len||!pos)
        return -2;
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
int  main()
{
    String *S=NULL,*S2=NULL,*S3=NULL,*S4=NULL,*Sub=NULL,*Sub2=NULL,*Tstring=NULL;
    int x, cnt = 0;
    do
    {
        printf("1-Create a new string\n");
        printf("2-Insert a String to the primary string\n");
        printf("3-Cat a String to the primary string\n");
        printf("4-Find the Sub String in String\n");
        printf("5-Replace one Sub String in String\n");
        printf("0-Exit\n");
        scanf("%d", &x);
        switch(x){
            case 1:
                cnt++;
                S = Create();
                char s[100];
                printf("Please input your String:");
                getchar();
                gets(s);
                Assign(S, s);
                printf("Below is your String:\n");
                printString(S);
                printf("\n\n");
                //free(s);
                break;
            case 2:
                if(cnt){
                    S2 = Create();
                    int pos1 = 0;
                    char s2[100];
                    printf("Please input the String you want to insert:");
                    fflush(stdin);
                    gets(s2);
                    Assign(S2, s2);
flag1:              printf("\nNow Please input the pos you want to insert:");
                    scanf("%d", &pos1);
                    if(pos1>=Getlen(S->data)+2){
                        printf("The pos is illegal! Please input again!");
                        goto flag1;
                    }
                    printf("Below is the primary string:\n");
                    printString(S);
                    printf("\n\n");
                    Insert(S, pos1, S2);
                    printf("Below is the inserted string(the overflow will be overlooked):\n");
                    printString(S);
                    printf("\n\n");
                    break;
                }else{
                    printf("No String in memory! Please Create a String first!\n");
                    continue;
                }
            case 3:
            if(cnt){
                S3 = Create();
                char s3[100];
                printf("Please input the string you want to cat:");
                fflush(stdin);
                gets(s3);
                Assign(S3, s3);
                printf("Below is the primary string:\n");
                printString(S);
                printf("\n\n");
                CatString(S, S3);
                printf("Below is the inserted string(the overflow will be overlooked):\n");
                printString(S);
                printf("\n\n");
                break;
            }else{
                printf("No String in memory! Please Create a String first!\n");
                continue;
            }
            case 4:
            if(cnt){
                S4 = Create();
                Sub = Create();
                char s4[100];
                int pos2 = 0,ret=0;
                printf("Please input the Sub String you want to find:");
                fflush(stdin);
                gets(s4);
                Assign(S4, s4);
flag2:          printf("Please input the pos that the finding begin:");
                scanf("%d", &pos2);
                ret=FindSubString(S, S4, pos2);
                if(ret==-2){
                    printf("The pos is illegal! Please input again!\n");
                    goto flag2;
                }else if(ret==-1){
                    printf("No such sub string in the String!\n");
                }else{
                    printf("The sub string appear firstly in pos %d\n", ret);
                }
                break;
            }else{
                printf("No String in memory! Please Create a String first!\n");
                continue;
            }
            case 5:
            if(cnt){
                Sub2 = Create();
                Tstring = Create();
                char sub[100];
                char T[100];
                int pos3 = 0,ret2=0;
                printf("Please input the sub string you want to replace:");
                fflush(stdin);
                gets(sub);
                Assign(Sub2, sub);
flag3:          printf("Please input the pos that the finding begin:");
                scanf("%d", &pos3);
                ret2 = FindSubString(S, Sub2, pos3);
                if (ret2 == -2)
                {
                    printf("The pos is illegal! Please input again!\n");
                    goto flag3;
                }
                else if (ret2 == -1)
                {
                    printf("No such sub string in the String!\n");
                }
                else
                {
                    printf("Please input the string you want to use to replace:");
                    fflush(stdin);
                    gets(T);
                    Assign(Tstring, T);
                    printf("Below is the primary string:\n");
                    printString(S);
                    printf("\n\n");
                    Replace(S, pos3, Sub2, Tstring);
                    printf("Below is the inserted string(the overflow will be overlooked):\n");
                    printString(S);
                    printf("\n\n");
                }
                break;
            }else{
                printf("No String in memory! Please Create a String first!\n");
                continue;
            }
            case 0:
                printf("Thanks to use!\n");
                exit(1);
        }
    } while(x);
    return 0;
}
