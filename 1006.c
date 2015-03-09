#include<stdio.h>
#include<string.h>
int main()
{
    char fid[16],ftime[9],lid[16],ltime[9];
    char id[16],itime[9],otime[9];
    int i=0,n;
    strcpy(ftime,"24:00:00");
    strcpy(ltime,"00:00:00");
    scanf("%d",&n);
    while(i++<n)
    {
        scanf("%s %s %s",&id,&itime,&otime);
        if(strcmp(ftime,itime)>0)
        {
            strcpy(fid,id);
            strcpy(ftime,itime);
        }
        if(strcmp(otime,ltime)>0)
        {
            strcpy(lid,id);
            strcpy(ltime,otime);
        }
    }
    printf("%s %s\n",fid,lid);
    return 0;
}
