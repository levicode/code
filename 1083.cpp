#include<stdio.h>
struct Student
{
	char name[11];
	char id[11];
	int grade;
};
int main()
{
	int n,i=0,j,low,high;
	scanf("%d",&n);
	Student stu[n];
	while(i<n)
	{
		scanf("%s %s %d",&stu[i].name,&stu[i].id,&stu[i].grade);
		i++;
	}
	scanf("%d %d",&low,&high);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[i]<stu[j])
			{
				Student temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(stu[i].grade>=low&&stu[i].grade<=high)
			printf("%s %s\n",stu[i].name,stu[i].id);
	}
	return 0;
}
