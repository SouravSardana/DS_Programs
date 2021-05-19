#include <iostream>

using namespace std;
int maxprod(int arr[],int n)
{
    int maxVal=arr[0],minVal=arr[0],res=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<0)
            swap(minVal,maxVal);
        maxVal = max(arr[i],arr[i]*maxVal);
        minVal = min(arr[i],arr[i]*minVal);
        res=max(maxVal,res);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxprod(arr,n);
    return 0;
}
