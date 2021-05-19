#include <iostream>
#include <vector>
using namespace std;
void posneg(int arr[],int n)
{
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    int k=0;
    for(int i=0;i<pos.size();i++)
        arr[k++]=pos[i];
    for(int i=0;i<neg.size();i++)
        arr[k++]=neg[i];
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    posneg(arr,n);
    return 0;
}
