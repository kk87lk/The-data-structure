int main(){
        String *S = Create();
        String *S2 = Create();
        char s[100],s2[100];
        gets(s);
        gets(s2);
        Assign(S,s);
        Assign(S2, s2);
        Insert(S, 2, S2);
        printString(S);
        printf("\n");
        Delete(S, 2, 3);
        printString(S);
    }