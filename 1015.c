#include<stdio.h>
#include<math.h>
int prime(int a)
{
	if(a==1)
		return 0;
	if(a==2)
		return 1;
    int i; 
    for(i=2;i<=a/2;i++)
        if(a%i==0)
            break;
    return i>a/2?1:0;
}
int reserve(int n,int d)
{
    int num[14],k=0,sum=0,i;
    while(n)
    {
        num[k++]=n%d;
        n/=d;
    }
    for(i=0;i<k;i++)
            sum+=num[i]*pow(d,k-1-i);
    return sum;
}
int main()
{
    int ans[500],n,d,m=0,i;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
            break;
        scanf("%d",&d);
        if(!prime(n))
        {
            ans[m++]=0;
            continue;
        }
        int temp=reserve(n,d);
        if(prime(temp))
            ans[m++]=1;
        else
            ans[m++]=0;
    }
    for(i=0;i<m;i++)
    {
        if(ans[i])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
