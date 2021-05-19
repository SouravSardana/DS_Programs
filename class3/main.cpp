#include <iostream>

using namespace std;

int main()
{
    int val=1;
    int n;
    cin>>n;
    int arr[n];
    int i=0,j=n-1;
    while(i<j)
    {
        arr[i++]=val++;
        arr[j--]=val++;
    }
    if(i==j)
        arr[i]=val++;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
