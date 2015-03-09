#include<stdio.h>
int main()
{
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    int color[m*n],cn=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&color[cn++]);
        }
    }
    int count[m*n][2],cs=0;
    for(i=0;i<cn;i++)
    {
        for(j=0;j<cs;j++)
        {
            if(color[i]==count[j][0])
            {
                count[j][1]++;
                break;
            }
        }
        if(j==cs)
        {
            count[cs][0]=color[i];
            count[cs][1]=1;
            cs++;
        }
    }
    //for(i=0;i<cs;i++)
    //    printf("%d %d\n",count[i][0],count[i][1]);
    int max=0,num;
    for(i=0;i<cs;i++)
    {
        if(count[i][1]>max)
        {
            max=count[i][1];
            num=count[i][0];
        }
    }
    printf("%d\n",num);
    return 0;
}
