#include<stdio.h>
int main()
{
	int hour,min,a,b;
	scanf("%d %d",&a,&b);
	min=a%100+b%60;
	if(min>=0)
	{
		hour=a/100+b/60+min/60;
		min=min%60;
	}
	else
	{
		hour=a/100+b/60-(-min)/60-1;
		min+=((-min)/60+1)*60;
	}
	printf("%d",hour*100+min);
	return 0;
}
