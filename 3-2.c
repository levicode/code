#include<stdio.h>
int main()
{
	int a,b,c,ans;
	scanf("%d %d %d",&a,&b,&c);
	if(a==b)
		ans=3;
	else if(a==c)
		ans=2;
	else
		ans=1;
	if(ans==1)
		printf("A");
	else if(ans==2)
		printf("B");
	else
		printf("C");
	return 0;
} 
