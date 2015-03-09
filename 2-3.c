#include<stdio.h>
int main()
{
	int ans,a,b,c;
	scanf("%d",&ans);
	c=ans%10;
	ans/=10;
	b=ans%10;
	a=ans/10;
	ans=a+b*10+c*100;
	printf("%d",ans);
	return 0;
}
