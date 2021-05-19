#include <iostream>

using namespace std;
void mergearr(int arr1[],int arr2[],int n,int m)
{
    int i=0,j=0,k=0;
    int c[m+n];
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
            c[k++]=arr1[i++];
        else
            c[k++]=arr2[j++];
    }
    while(i<n)
        c[k++]=arr1[i++];
    while(j<m)
        c[k++]=arr2[j++];
    for(int i=0;i<k;i++)
        cout<<c[i]<<" ";
}
int main()
{
    int arr1[]={10,15,20,40};
    int arr2[]={5,6,6,10,15};
    mergearr(arr1,arr2,4,5);
    return 0;
}
