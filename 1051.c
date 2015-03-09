#include<stdio.h>
int main()
{
	int m,n,k,i=0;
	scanf("%d %d %d",&m,&n,&k);
	int ans[k];
	while(i<k)
	{
		int seq[n];
		for(j=0;j<n;j++)
			scanf("%d",&seq[j]);
		int stack[m],top=-1,p=0,q=1;
		while(true)
		{
			if(top&&stack[top]==seq[p])
			{
				top--;
			}
			else if(q==seq[p])
			{
				p++;
				q++;
			}
			else if(top<m-1)
			{
				stack[++top]=q++;
			}
			else
			{
				ans[i]=0;
			}
		}
		
	}
	for(i=0;i<k;i++)
	{
		if(ans[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
