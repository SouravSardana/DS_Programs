#include <iostream>

using namespace std;

void rotat(int arr[],int n)
{
    int temp=arr[n-1];
    for(int i=n-2;i>=0;i--)
        arr[i+1]=arr[i];
    arr[0]=temp;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={1,2,8,3,4,5};
    rotat(arr,6);
    return 0;
}
