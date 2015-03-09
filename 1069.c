#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,num[4];
    while(1)
    {
    for(i=0;i<4;i++)
    {
        num[i]=n%10;
        n/=10;
    }
    int a=0,b=0,c;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(num[i]<num[j])
            {
                int temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
        a+=num[i]*pow(10,3-i);
        b+=num[i]*pow(10,i);
    }
    c=a-b;
    printf("%04d - %04d = %04d\n",a,b,c);
    if(c==0000||c==6174)
        break;
    else
        n=c;
    }
    return 0;
}
