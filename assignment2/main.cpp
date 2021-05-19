#include <iostream>

using namespace std;

int findDigit(int num)
{
    int res=0;
    while(num>0)
    {
        res+=num%10;
        num/=10;
    }
    return res;
}
int main()
{
    int n;
    int sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        sum+=arr[i];
    while(sum/10!=0)
        sum = findDigit(sum);
    cout<<sum;
    return 0;
}
