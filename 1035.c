#include<stdio.h>
#include<string.h>
struct User
{
    char name[11];
    char passwd[11];
    int flag;
};
int main()
{
    int n,m=0,i=0,j;
    scanf("%d",&n);
    struct User users[n];
    while(i<n)
    {
        scanf("%s %s",users[i].name,users[i].passwd);
        users[i++].flag=0;
    }
    for(i=0;i<n;i++)
    {
        int k=strlen(users[i].passwd);
        for(j=0;j<k;j++)
        {
            switch(users[i].passwd[j])
            {
                case '1':
                    users[i].passwd[j]='@';
                    users[i].flag=1;
                    break;
                case '0':
                    users[i].passwd[j]='%';
                    users[i].flag=1;
                    break;
                case 'l':
                    users[i].passwd[j]='L';
                    users[i].flag=1;
                    break;
                case 'O':
                    users[i].passwd[j]='o';
                    users[i].flag=1;
                    break;
                default:
                    break;
            }
        }
        if(users[i].flag)
            m++;
    }
    if(m==0)
    {
        if(n==1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified",n);
    }
    else
    {
        printf("%d\n",m);
        for(i=0;i<n;i++)
            if(users[i].flag)
                printf("%s %s\n",users[i].name,users[i].passwd);
    }
    return 0;
}
