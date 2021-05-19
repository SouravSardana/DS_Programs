#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int counter=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                swap(arr[counter],arr[i]);
                counter++;
            }
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    return 0;
}
