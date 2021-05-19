#include <iostream>

using namespace std;
void mer(int arr1[],int arr2[],int m,int n)
{
    int i=0,j=0,k=0;
    int arr[m+n];
    while(i<m && j<n)
    {
        if(arr1[i]<=arr2[j])
            arr[k++]=arr1[i++];
        else
            arr[k++]=arr2[j++];
    }
    while(i<m)
        arr[k++]=arr1[i++];
    while(j<n)
        arr[k++]=arr2[j++];
    for(int i=0;i<m+n;i++)
        cout<<arr[i]<<" ";

}
int main()
{
    int arr1[]={10,20,30,40,54};
    int arr2[]={4,11,15,25,34,60};
    mer(arr1,arr2,5,6);
    return 0;
}
