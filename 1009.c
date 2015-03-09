#include<stdio.h>
#include<string.h>
int main()
{
    int numa[10],numb[10],i=0,j=0,k=0,m,n;
    float counta[10],countb[10],sum[2001];
    memset(sum,0,sizeof(sum));
    scanf("%d",&m);
    while(i<m)
    {
        scanf("%d",&numa[i]);
        scanf("%f",&counta[i]);
        i++;
    }
    scanf("%d",&n);
    while(j<n)
    {
        scanf("%d",&numb[j]);
        scanf("%f",&countb[j]);
        j++;
    }
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            int num=numa[i]+numb[j];
            if(sum[num]==0)
                k++;
            sum[num]+=counta[i]*countb[j];
            if(sum[num]==0)
                k--;
        }
    printf("%d",k);
    for(i=2000;i>=0;i--)
    {
        if(sum[i])
            printf(" %d %.1f",i,sum[i]);
    }
    return 0;
}

