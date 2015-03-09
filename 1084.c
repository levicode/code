#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char a[81],b[81];
    scanf("%s",&a);
    scanf("%s",&b);
    int an=strlen(a),bn=strlen(b);
    int asc[180];
    int i,j;
    for(i=0;i<180;i++)
        asc[i]=0;
    for(i=0;i<bn;i++)
    {
        asc[b[i]]=1;
        if(b[i]>=97&&b[i]<=122)
            asc[b[i]-32]=1;
        else if(b[i]>=65&&b[i]<=90)
            asc[b[i]+32]=1;
    }
    for(i=0;i<an;i++)
    {
        if(asc[a[i]]==0)
        {
            printf("%c",a[i]);
            asc[a[i]]=1;
            if(a[i]>=97&&a[i]<=122)
            {
                asc[a[i]-32]=1;
                printf("%c",a[i]+32);
            }
            else if(a[i]>=65&&a[i]<=90)
            {
                asc[a[i]+32]=1;
                printf("%c",a[i]);
            }
            else
                printf("%c",a[i]);
        }
    }
    return 0;
}
