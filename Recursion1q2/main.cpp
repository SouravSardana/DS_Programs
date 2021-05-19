#include <bits/stdc++.h>

using namespace std;
void SumTri(int arr[],int n)
{
    int temp[n-1];
    if(n==0)
        return;
    for(int i=0;i<n-1;i++)
        temp[i]=arr[i]+arr[i+1];
    SumTri(temp,n-1);
    for(int i=0;i<n-1;i++)
        cout<<temp[i]<<" ";
    cout<<endl;

}
int main()
{
    int arr[]={1,2,3,4,5};
    SumTri(arr,5);
    return 0;
}
