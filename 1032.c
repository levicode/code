#include<stdio.h>
struct Node
{
    int addr;
    char data;
    int next;
};
int index(int addr,struct Node *nodes,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(nodes[i].addr==addr)
            break;
    return i<n?i:-1;
}
int main()
{
    int start[2],n;
    scanf("%d",&start[0]);
    scanf("%d",&start[1]);
    scanf("%d",&n);
    struct Node nodes[n];
    int i=0,j;
    while(i<n)
    {
        scanf("%d %c %d",&nodes[i].addr,&nodes[i].data,&nodes[i].next);
        i++;
    }
    char ch[2][20];
    int length[2]={0,0};
    for(i=0;i<2;i++)
    {
        int current=index(start[i],nodes,n);
        if(current==-1)
        {
            printf("-1");
            return 0;
        }
        while(1)
        {
            ch[i][length[i]++]=nodes[current].data;
            if(nodes[current].next!=-1)
                current=index(nodes[current].next,nodes,n);
            else
                break;
        }
    }
    i=length[0]-1;
    j=length[1]-1;
    while(i>=0&&j>=0&&ch[0][i]==ch[1][j])
    {
        i--;
        j--;
    }
    if(i==length[0]-1)
        printf("-1");
    else
    {
        for(j=0;j<n;j++)
            if(nodes[j].data==ch[0][i+1])
                break;
        printf("%05d",nodes[j].addr);
    }
    return 0;
}
