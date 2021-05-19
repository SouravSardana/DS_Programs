#include <iostream>
#include <algorithm>
using namespace std;
void inter(int a[],int b[],int m,int n)
{
    sort(a,a+m);
    sort(b,b+n);
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(a[i]==b[j])
        {
            cout<<a[i]<<" ";
            i++;
            j++;
        }
        else if(a[i]>b[j])
            j++;
        else
            i++;
    }
}
int main()
{
    int arr1[]={40,40,10,60};
    int arr2[]={40,30,16,40};
    inter(arr1,arr2,4,4);
    return 0;
}
