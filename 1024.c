#include<stdio.h>
#include<string.h>
int main()
{
    char ch[11];
    int k,count=0,num[1000],pal[1000],i;
    memset(num,0,sizeof(num));
    memset(pal,0,sizeof(pal));
    scanf("%s %d",&ch,&k);
    int n=strlen(ch);
    for(i=0;i<n;i++)
        num[i]=ch[n-1-i]-'0';
    while(count<k)
    {
        count++;
        for(i=0;i<n;i++)
            pal[i]=num[n-1-i];
        for(i=0;i<n;i++)
        {
            num[i]+=pal[i];
            if(num[i]>9)
            {
                num[i]-=10;
                if(i+1<n)
                    num[i+1]++;
                else
                    num[i+1]=1;
            }
        }
        if(num[n]==1)
            n++;
        for(i=0;i<n/2;i++)
        {
            if(num[i]!=num[n-1-i])
                break;
        }
        if(i==n/2)
            break;
    }
    for(i=n-1;i>=0;i--)
        printf("%d",num[i]);
    printf("\n%d",count);
    return 0;
}
