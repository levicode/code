#include <stdio.h>
#include <string.h>

int main()
{
	char str1[1001], str2[1001];
	int asc[128] = {0};
	int i, clack = 0, cremain = 0;
	
	scanf("%s", &str1);
	scanf("%s", &str2);
	
	for(i = 0; i < strlen(str1); i++)
	{
		asc[str1[i]]++;
	}
	for(i = 0; i < strlen(str2); i++)
	{
		asc[str2[i]]--;
	}
	
	for(i = 0; i < 128; i++)
	{
		if(asc[i] > 0)
		{
			cremain += asc[i];
		}
		else if(asc[i] < 0)
		{
			clack -= asc[i];
		}
	}
	
	if(clack > 0)
	{
		printf("No %d\n", clack);
	}
	else
	{
		printf("Yes %d\n", cremain);
	}
	
	return 0;
}
