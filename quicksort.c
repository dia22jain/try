#include<stdio.h>
void quick_sort(int a[], int low, int high);
int partition (int a[],int n, int x);
int main()
{
    int arr[]={50,9,76,36,90,110,67,28,100};
    int n=9;
    quick_sort(arr,0,n-1);
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}
int partition(int a[],int x, int n)
{
    int i,j,t;
    i=0;
    j=n;
    while(i<j && a[i]<=x)
       i++;
    while(i<j&& a[j]>x)
       j--;
    if (a[j]>x)
        j=j-1;
    while(i<j)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;
        j--;
        while(a[i]<=x)
             i++;
        while(a[j]>x)
             j--;
    }
      return j;
}
void quick_sort(int a[], int low, int high)
{
    int p,t;
    if(low<high)
    {
        p=partition(a,a[low],high);
        t=a[p];
        a[p]=a[low];
        a[low]=t;
        quick_sort(a,low,p-1);
        quick_sort(a,p+1,high);
    }
}