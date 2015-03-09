#include<stdio.h>
#include<math.h>
int main()
{
    int n,b,i=1,j=0;
    scanf("%d %d",&n,&b);
    while(pow(b,i)<=n)
        i++;
    int num[i];
    while(n/b)
    {
        num[j++]=n%b;
        n/=b;
    }
    num[j++]=n%b;
    for(i=0;i<j/2;i++)
    {
        if(num[i]!=num[j-1-i])
            break;
    }
    if(i==j/2)
        printf("Yes\n");
    else
        printf("No\n");
    for(i=j-1;i>0;i--)
    {
        printf("%d ",num[i]);
    }
    printf("%d",num[0]);
    return 0;
}
