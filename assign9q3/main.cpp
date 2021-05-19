#include <iostream>

using namespace std;
int cal_median(int arr1[],int arr2[],int m,int n)
{
    int m1,m2;
    if((n+m)%2==1)
    {
        int i=0,j=0;
        for(int k=0;k<=(n+m)/2;k++)
        {
            if(i<m && j<n)  // i->arr1[i],j->arr2[j];
                m1=arr1[i]>arr2[j]?arr2[j++]:arr1[i++]; // if(arr[i]>arr[j]) m1= arr[j],j++;
            else if(i<m)
                m1=arr1[i++];
            else
                m1=arr2[j++];
        }
        return m1;
    }
    else
    {
        int i=0,j=0;
        for(int k=0;k<=(n+m)/2;k++)
        {
            m2=m1; // 1 2 3 4 5 6  (6/2)
            if(i<m && j<n)
                m1=arr1[i]>arr2[j]?arr2[j++]:arr1[i++];
            else if(i<m)
                m1=arr1[i++];
            else
                m1=arr2[j++];
        }
        return (m1+m2)/2;
    }
}
int main()
{
    int arr1[]={1,4,10,11,12,13};
    int arr2[]={2,3,5,6,8,9};
    cout<<cal_median(arr1,arr2,6,6);
}
