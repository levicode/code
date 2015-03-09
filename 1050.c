#include<stdio.h>
#include<string.h>
int main()
{
    char s1[10001],s2[10001];
    gets(s1);
    gets(s2);
    int n1=strlen(s1);
    int n2=strlen(s2);
    int asc[127];
    memset(asc,0,sizeof(asc));
    int i,j;
    for(i=0;i<n2;i++)
        asc[s2[i]]=1;
    for(i=0;i<n1;i++)
        if(!asc[s1[i]])
            printf("%c",s1[i]);
    return 0;
}
