#include<stdio.h>
#include<stdlib.h>
struct Customer
{
    int arrive;
    int time;
    int wait;
};
struct Window
{
    int service;
    int onservice;
};
int cmp(const void *a,const void *b)
{
    return (*(const struct Customer *)a).arrive
        -(*(const struct Customer *)b).arrive;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    struct Customer customers[n];
    int i,j,a,b,c,d;
    for(i=0;i<n;i++)
    {
        scanf("%d:%d:%d",&a,&b,&c);
        customers[i].arrive=(a*60+b)*60+c;
        scanf("%d",&d);
        customers[i].time=d*60;
    }
    qsort(customers,n,sizeof(struct Customer),cmp);
    struct Window windows[k];
    for(i=0;i<k;i++)
    {
        windows[i].service=28800;
        windows[i].onservice=0;
    }
    int m=0;
    for(i=28800;i<=61200&&m<n;i++)
    {
        for(j=0;j<k&&m<n;j++)
        {
            if(windows[j].onservice&&i==windows[j].service)
                windows[j].onservice=0;
            if(windows[j].onservice==0&&customers[m].arrive<=i)
            {
                customers[m].wait=i-customers[m].arrive;
                windows[j].service=i+customers[m].time;
                windows[j].onservice=1;
                m++;
            }
        }
    }
    int sum=0;
    for(i=0;i<m;i++)
        sum+=customers[i].wait;
    //float average=(float)sum/m/60;
    if(m)
        printf("%0.1f\n",(float)sum/m/60);
    else
        printf("0.0\n");
    return 0;
}
