#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(int k[],int s,int t)
{
    int i,j;
    if(s<t)
    {
        i=s;
        j=t+1;
        while(1)
        {
            do i++;
            while(!k[s]>=k[i]||i==t);
            do j--;
            while(!k[s]<=k[j]||j==s);
            if(i<j)
                swap(&k[i],&k[j]);
            else
                break;
        }
        swap(&k[s],&k[j]);
        quicksort(k,s,j-1);
        quicksort(k,j+1,t);
    }
}

int main()
{
    int a[10],n,i=0;
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d",&a[i++]);
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
