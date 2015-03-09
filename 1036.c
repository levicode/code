#include<stdio.h>
#include<string.h>
#include<math.h>
struct Student
{
	char name[11];
	char gender;
	char id[11];
	int grade;	
};
int main()
{
	struct Student m,f,temp;
	m.grade=101;
	f.grade=-1;
	int n,i=0;
	scanf("%d",&n);
	while(i++<n)
	{
		scanf("%s %c %s %d",&temp.name,&temp.gender,&temp.id,&temp.grade);
		if(temp.gender=='M'&&temp.grade<m.grade)
			m=temp;
		else if(temp.gender=='F'&&temp.grade>f.grade)
			f=temp;
	}
	if(f.grade==-1)
		printf("Absent\n");
	else
		printf("%s %s\n",f.name,f.id);
	if(m.grade==101)
	printf("Absent\n");
	else
		printf("%s %s\n",m.name,m.id);
	if(f.grade==-1||m.grade==101)
		printf("NA\n");
	else
		printf("%d\n",abs(f.grade-m.grade));
	return 0;
}
