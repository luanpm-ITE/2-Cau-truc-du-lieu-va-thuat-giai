

#include <stdio.h>
#include <stdlib.h>
int linearSearch(int[],int,int);
int binerySearch(int[],int,int);
int main()
{
    int a[]={1,2,4,8,16,32};
    int n=6,x=1;
    int kq=binerySearch(a,n,x);
    if(kq==1) printf("\nTim thay x");
    else printf("\nKhong tim thay x");
    return 0;
}
int linearSearch(int a[],int n,int x)
{
    int i=0;
    a[n]=x;
    while(a[i]!=x)
        ++i;
    if(i==n) return 0;
    else return 1;
}
int binerySearch(int a[],int n,int x)
{
    int l=0,r=n-1,m;
    while(l<r)
    {
        m=(l+r)/2;
        if(a[m]==x) return 1;
        else if(a[m]>x)
            r=m-1;
        else l=m+1;
    }
    return 0;
}