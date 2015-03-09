#include<stdio.h>
#include<stdlib.h>
struct Student
{
    char id[7];
    char name[9];
    int grade;
};

int main()
{
    int n,c;
    scanf("%d %d",&n,&c);
    struct Student stu[n];
    int i,j;
    for(i=0;i<n;i++)
        scanf("%s %s %d",&stu[i].id,&stu[i].name,&stu[i].grade);

    return 0;
}
