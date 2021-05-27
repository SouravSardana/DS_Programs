//Check if a key is present in every segment of size k in an array.
#include <iostream>

using namespace std;

bool CheckAvail(int arr[],int n,int k,int element)
{
    for(int j=0;j<n;j+=k)
    {
        bool isPresent=false;
        for(int i=j;i<k+j;i++)
        {
            if(arr[i]==element)
            {
                isPresent=true;
                break;
            }
        }
        if(!isPresent)
            return false;
    }
    return true;
}
int main()
{
    int arr[]={3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3};
    cout<<CheckAvail(arr,12,3,3);
    return 0;
}
