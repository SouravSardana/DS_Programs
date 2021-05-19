#include <iostream>

using namespace std;

/*my method
void sort012(int a[], int n)
{
        int z=0,o=0,t=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                z++;
            else if(a[i]==1)
                o++;
            else
                t++;
        }
        for(int i=0;i<z;i++)
           a[i]=0;
        for(int i=z;i<z+o;i++)
            a[i]=1;
        for(int i=z+o;i<n;i++)
            a[i]=2;
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
}*/
// Better method with one traversal
void sort012(int arr[],int n)
{
    int low=0,high=n-1,mid=0;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
        else if(arr[mid]==1)
            mid++;
    }
    for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={0,1,0,0,2,2,1,0};
    sort012(arr,8);
    return 0;
}
