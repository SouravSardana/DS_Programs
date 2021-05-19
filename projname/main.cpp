#include <iostream>
#include <vector>
using namespace std;
void alter(int arr[],int n)
{
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    int i=0,j=0,k=0;
    while(i<pos.size() && j<neg.size())
    {
        arr[k++]=neg[j++];
        arr[k++]=pos[i++];
    }
    while(i<pos.size())
    {
        arr[k++]=pos[i++];
    }
    while(j<neg.size())
    {
        arr[k++]=neg[j++];
    }
}
int main()
{
    int arr[]={-5,-2,5,2,4,7,1,8,0,-8};
    alter(arr,10);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
    return 0;
}
