#include <iostream>

using namespace std;
int sum(int arr[],int n)
{
    if(n==0)
        return 0;
    return(arr[n-1]+sum(arr, n-1));
}
int main()
{
    int arr[]={1,2,3};
    cout<<sum(arr,3);
    return 0;
}
