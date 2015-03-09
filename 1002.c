#include<stdio.h>
#include<string.h>
int main()
{
    int num,i=0,j=0,m,n=0;
    float sum[1001],count;
    memset(sum,0,sizeof(sum));
    scanf("%d",&m);
    n+=m;
    while(i++<2*m)
    {
        if(i%2)
            scanf("%d",&num);
        else
        {
            scanf("%f",&count);
            sum[num]+=count;
        }
    }
    scanf("%d",&m);
    while(j++<2*m)
    {
        if(j%2)
            scanf("%d",&num);
        else
        {
            scanf("%f",&count);
            if(sum[num]==0)
                n++;
            sum[num]+=count;
            if(sum[num]==0)
                n--;
        }
    }
    printf("%d",n);
    for(i=1000;i>=0;i--)
    {
        if(sum[i])
        {
            printf(" %d %.1f",i,sum[i]);
        }
    }
    return 0;
}
