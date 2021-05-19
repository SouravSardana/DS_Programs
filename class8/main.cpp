#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
                arr[k++]=arr[i];
        }
        for(int i=k;i<n;i++)
            arr[i]=0;
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }
    return 0;
}
