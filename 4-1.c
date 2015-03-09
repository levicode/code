#include<stdio.h>
int main()
{
	int n,start=1,i=1,j,count,num,power;
	scanf("%d",&n);
	while(i<n)
	{
		start*=10;
		i++;
	}
	for(i=start;i<start*10;i++)
	{
		count=0;
		num=i;
		while(num>0)
		{
			j=0;
			power=1;
			while(j<n)
			{
				power*=num%10;
				j++;
			}
			count+=power;
			num/=10;
		}
		if(count==i)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
