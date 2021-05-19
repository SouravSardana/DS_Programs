#include <iostream>

using namespace std;

int maxsum(int arr[],int n)
{   int res = arr[0];
    int maxi = arr[0];
    for(int i=1;i<n;i++)
    {
        maxi = max(arr[i],maxi+arr[i]);
        res = max(maxi,res);
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
    cout<<maxsum(arr,n);
    return 0;
}
