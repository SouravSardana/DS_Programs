#include <iostream>

using namespace std;
int rev(int number)
{
    int res=0;
    while(number>0)
    {res=(res*10)+(number%10);
    number/=10;}
    return res;
}
bool check_palin(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int num=rev(arr[i]);
        if(num!=arr[i])
            return false;

    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<check_palin(arr,n);
    return 0;
}
