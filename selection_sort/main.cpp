#include <iostream>

using namespace std;
void select(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int mini = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[mini])
                mini=j;
        }
        swap(arr[i],arr[mini]);
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={4,2,1,5,32,12};
    select(arr,6);
    return 0;
}
