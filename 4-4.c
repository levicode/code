#include<stdio.h>
int main()
{
	int randnum,n,num,a=0,ans[100],i,j;
	scanf("%d %d",&randnum,&n);
	while(1)
	{
		scanf("%d",&num);
		ans[a++]=num;
		if(num<0)
		{
			break;
		}
	}
	for(i=0;i<a;i++)
	{
		if(i>=n)
		{
			printf("Game Over\n");
			break;
		}
		else
		{
			if(ans[i]<0)
			{
				printf("Game Over\n");
				break;
			}
			else
			{
				 if(ans[i]==randnum)
				{
					if(i==0)
					{
						printf("Bingo!\n");
					}
					else if(i<3)
					{
						printf("Lucky You!\n");
					}
					else
					{
						printf("Good Guess!\n");
					}
					break;
			    }
			    else
				{
					if(i+1==n&&a-1==n)
					{
						printf("Game Over\n");
						break;
					}
					else if(ans[i]>randnum)
					{
						printf("Too big\n");
					}
					else
					{
						printf("Too small\n");
					}
				}
			}
		}
	}
	return 0;
} 
