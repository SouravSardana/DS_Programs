#include <iostream>

using namespace std;
int searching(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}
int main()
{
    int n;
    int x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>x;
    cout<<searching(arr,n,x);
    return 0;
}
