#include <iostream>

using namespace std;

int main()
{
    int n,sum;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the pair sum: " ;
    cin>>sum;
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==sum)
                count++;
        }
    }
    cout<<"no. of pairs are:"<<count;
    return 0;
}
