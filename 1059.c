#include<stdio.h>
#define MAX 1000
struct Num
{
    long base;
    int count;
};
int main()
{
    long n,i;
    struct Num num[MAX];
    int j,m=0;
    for(j=0;j<MAX;j++)
        num[j].count=0;
    scanf("%ld",&n);
    printf("%ld=",n);
    for(i=2;i<n/2;i++)
    {
        int count=0;
        while(n%i==0)
        {
            count++;
            n/=i;
        }
        if(count)
        {
            num[m].base=i;
            num[m].count=count;
            m++;
        }
    }
    if(m==0)
    {
        printf("%ld",n);
        return 0;
    }
    for(j=0;j<m;j++)
    {
        printf("%ld",num[j].base);
        if(num[j].count>1)
            printf("^%d",num[j].count);
        if(j<m-1)
            printf("*");
    }
    if(n!=1)
    printf("*%ld",n);
    return 0;
}
