#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char s1[101],s2[101];
    scanf("%d",&n);
    scanf("%s",&s1);
    scanf("%s",&s2);
    int n1=strlen(s1);
    int n2=strlen(s2);
    int i=0,j,point1,point2;
    while(i<n1-1)
    {
        if(s1[i]=='0')
        {
            if(s1[i+1]=='.')
                break;
            else
            {
                for(j=i;j<n1-1;j++)
                    s1[j]=s1[j+1];
                n1--;
            }
        }
        else
            break;
    }
    i=0;
    while(i<n2-1)
    {
        if(s2[i]=='0')
        {
            if(s2[i+1]=='.')
                break;
            else
            {
                for(j=i;j<n2-1;j++)
                    s2[j]=s2[j+1];
                n2--;
            }
        }
        else
            break;
    }
    if(s1[0]=='0')
    {
        for(i=2;i<n1;i++)
            if(s1[i]!='0')
                break;
        if(i<n1)
            point1=-(i-2);
        else
            point1=0;
    }
    else
    {
        for(i=0;i<n1;i++)
            if(s1[i]=='.')
                break;
        point1=i;
    }
    if(s2[0]=='0')
    {
        for(i=2;i<n2;i++)
            if(s2[i]!='0')
                break;
        if(i<n2)
            point2=-(i-2);
        else
            point2=0;
    }
    else
    {
        for(i=0;i<n2;i++)
            if(s2[i]=='.')
                break;
        point2=i;
    }
    char num1[n],num2[n];
    i=0;
    j=point1>0?0:-point1+2;
    while(i<n)
    {
        if(j>=n1)
            num1[i++]='0';
        else if(s1[j]=='.')
            j++;
        else
            num1[i++]=s1[j++];
    }
    i=0;
    j=point2>0?0:-point2+2;
    while(i<n)
    {
        if(j>=n2)
            num2[i++]='0';
        else if(s2[j]=='.')
            j++;
        else
            num2[i++]=s2[j++];
    }
    if(point1==point2)
    {
        for(i=0;i<n;i++)
        {
            if(num1[i]!=num2[i])
            {
                break;
            }
        }
        if(i==n)
        {
            printf("YES 0.");
            for(j=0;j<n;j++)
                printf("%c",num1[j]);
            printf("*10^%d",point1);
            return 0;
        }
    }
    printf("NO 0.");
    for(j=0;j<n;j++)
        printf("%c",num1[j]);
    printf("*10^%d",point1);
    printf(" 0.");
    for(j=0;j<n;j++)
        printf("%c",num2[j]);
    printf("*10^%d",point2);
    return 0;
}
