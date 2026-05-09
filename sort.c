

#include <stdio.h>
#include <stdlib.h>
int temp;
void interchangeSort(int[],int);
void selectionSort(int[],int);
void bubleSort(int[],int);
void insertionSort(int[],int);
int main()
{
    int a[]={3,1,7,8,2,32};
    int n=6;
    printf("\nMang hien tai: ");
    for(int i=0;i<n;++i)
    {
        printf("%d ",a[i]);
    }
    printf("\nMang sau khi sap tang: ");
    insertionSort(a,n);
    for(int i=0;i<n;++i)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void interchangeSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;++i)
        for(j=i+1;j<n;++j)
            if(a[i]>a[j])
            {
                temp=a[i];a[i]=a[j];a[j]=temp;
            }
}
void selectionSort(int a[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;++i)
    {
        min=i;
        for(j=i+1;j<n;++j)
        {
            if(a[min]>a[j])
                min=j;
        }
        temp=a[min];a[min]=a[i];a[i]=temp;
    }
}
void bubleSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;++i)
        for(j=n-1;j>i;--j)
            if(a[j-1]>a[j])
            {
                temp=a[j-1];a[j-1]=a[j];a[j]=temp;
            }
}
void insertionSort(int a[],int n)
{
    int i,x,pos;
    for(i=1;i<n;++i)
    {
        x=a[i];
        pos=i-1;
        while((pos>=0)&&(a[pos]>x))
        {
            a[pos+1]=a[pos];
            --pos;
        }
        a[pos+1]=x;
    }
}