/*Find the minimum and maximum element in an array*/
#include <iostream>

using namespace std;

int findMax(int arr[],int n)
{
    int maxElement=INT_MIN;
    for(int i=0;i<n;i++)
        maxElement=max(maxElement,arr[i]);
    return maxElement;
}

int findMin(int arr[],int n)
{
    int minElement=INT_MAX;
    for(int i=0;i<n;i++)
        minElement=min(minElement,arr[i]);
    return minElement;
}

int main()
{
    int arr[]={1,5,3,0,-9,90};
    cout<<findMax(arr,6)<<endl;
    cout<<findMin(arr,6);
    return 0;
}
