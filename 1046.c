#include<stdio.h>
int main()
{
    int n,m,i=1,j=0,a,b;
    scanf("%d",&n);
    int dis[n+1];
    while(i<=n)
        scanf("%d",&dis[i++]);
    scanf("%d",&m);
    int exit[m][2];
    while(j<2*m)
    {
        scanf("%d",&exit[j/2][j%2]);
        j++;
    }
    int ans[m];
    for(i=0;i<m;i++)
    {
        j=exit[i][0];
        a=0;
        while(j!=exit[i][1])
        {
            a+=dis[j];
            j++;
            if(j>n)
                j-=n;
        }
        j=exit[i][0];
        b=0;
        while(j!=exit[i][1])
        {
            j--;
            if(j<1)
                j+=n;
            b+=dis[j];
        }
        ans[i]=a<b?a:b;
    }
    for(i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
