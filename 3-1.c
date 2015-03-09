#include<stdio.h>
int main()
{
	int day;
	scanf("%d",&day);
	if(day%5>0&&day%5<4)
		printf("Fishing in day %d",day);
	else
		printf("Drying in day %d",day);
	return 0;
}
