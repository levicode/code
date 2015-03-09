#include<stdio.h>
int main()
{
	int m,n,count=0,sum=0,i,j,flag;
	scanf("%d %d",&m,&n);
	if(m==1)
	{
		m=2;
	}
	for(i=m;i<=n;i++)
	{
		flag=1;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			count++;
			sum+=i;
		}
	}
	printf("%d %d",count,sum);
	return 0;
} 
