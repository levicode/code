#include<stdio.h>
int main()
{
	int a,i,j,k,n=0;
	scanf("%d",&a);
	for(i=a;i<a+4;i++)
	{
		for(j=a;j<a+4;j++)
		{
			if(i==j)
			{
				continue;
			}
			for(k=a;k<a+4;k++)
			{
				if(i==k||j==k)
				{
					continue;
				}
				n++;
				printf("%d%d%d",i,j,k);
				if(n%6==0)
				{
					printf("\n");
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
	return 0;
} 
