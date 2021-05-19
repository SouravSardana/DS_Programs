#include <iostream>

using namespace std;
void swapAl(int arr[],int n)
{

    for(int i=0;i<n-1;i+=2)
    {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[] = {9,3,6,12,4,5};
    swapAl(arr,6);
    return 0;
}
