#include <iostream>
#include <unordered_set>
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
    cout<<endl;
}
void uni(int arr1[],int arr2[],int m,int n)
{
    unordered_set<int> s;
    for(int i=0;i<m;i++)
        s.insert(arr1[i]);
    for(int i=0;i<n;i++)
        s.insert(arr2[i]);
    unordered_set<int> :: iterator it;
    for(it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";
}
int main()
{

    int arr1[]={7,1,5,2,3,6};
    int arr2[]={3,8,6,20,7};
    inter(arr1,arr2,6,5);
    uni(arr1,arr2,6,5);
    return 0;
}


