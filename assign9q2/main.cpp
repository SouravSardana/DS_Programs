#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    float res;
    if(n%2==0)
        res = (arr[n/2]+arr[n/2-1])/2;
    else
        res=(float)arr[n/2];
    cout<<res;
    return 0;
}
