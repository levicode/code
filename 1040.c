#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1001];
    int i,j,k,max=1;
    //scanf("%s",&ch);
    gets(ch);
    int n=strlen(ch);
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            for(k=i;k<(j-i+1)/2+i;k++)
            {
                if(ch[k]!=ch[j+i-k])
                    break;
            }
            if(k==(j-i+1)/2+i)
            {
                if(j-i+1>max)
                    max=j-i+1;
                break;
            }
        }
    }
    printf("%d\n",max);
    return 0;
}
