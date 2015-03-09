#include<stdio.h>
#include<stdlib.h>
int cmp ( const void *a , const void *b)
{
        return *(int *)a - *(int *)b;
}
int main()
{
    int nc,np,money=0,i=0,j=0;
    scanf("%d",&nc);
    int coupons[nc];
    while(i<nc)
        scanf("%d",&coupons[i++]);
    scanf("%d",&np);
    int products[np];
    while(j<np)
        scanf("%d",&products[j++]);
  qsort(coupons,nc,sizeof(coupons[0]),cmp);
  qsort(products,np,sizeof(products[0]),cmp);
     i=nc-1;
     j=np-1;
     while(i>=0&&j>=0&&coupons[i]>0&&products[j]>0)
         money+=coupons[i--]*products[j--];
     i=0;
     j=0;
     while(i<nc&&j<np&&coupons[i]<0&&products[j]<0)
         money+=coupons[i++]*products[j++];
     printf("%d\n",money);
    return 0;
}


