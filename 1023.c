#include<stdio.h>
#include<string.h>
int main()
{
    char sin[21],dou[21];
    int num[20],i,j;
    scanf("%s",&sin);
    int n=strlen(sin);
    for(i=0;i<n;i++)
        num[i]=(sin[i]-'0')*2;
    for(i=n-1;i>0;i--)
    {
        if(num[i]>9)
        {
            num[i]-=10;
            dou[i]='0'+num[i];
            num[i-1]++;
        }
        else
            dou[i]='0'+num[i];
    }
    if(num[0]<10)
    {
        dou[0]='0'+num[0];
        int flag[n];
        memset(flag,0,sizeof(flag));
        for(i=0;i<n;i++)
        {
            int found=0;
            for(j=0;j<n;j++)
            {
                if(flag[j]==0&&dou[i]==sin[j])
                {
                    flag[j]=1;
                    found=1;
                    break;
                }
            }
            if(!found)
                break;
        }
        if(i==n)
        {
            printf("Yes\n");
            for(j=0;j<n;j++)
                printf("%d",num[j]);
            return 0;
        }
    }
    printf("No\n");
    for(i=0;i<n;i++)
        printf("%d",num[i]);
    return 0;
}
