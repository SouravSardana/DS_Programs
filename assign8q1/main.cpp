#include <iostream>

using namespace std;
void negpos(int arr[],int n)
{
    int counter=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            swap(arr[i],arr[counter]);
            counter++;
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={-12,11,-13,-5,6,-7,5,-3,-6};
    negpos(arr,9);
    return 0;
}
