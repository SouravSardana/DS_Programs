#include <iostream>
#include <unordered_set>

using namespace std;
void intersect(int arr1[],int arr2[],int m,int n)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(arr1[i]>arr2[j])
            j++;
        else if(arr1[i]<arr2[j])
            i++;
        else
        {
            cout<<arr1[i++]<<" ";
            j++;
        }
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
    int arr1[]={1,3,4,5,7};
    int arr2[]={2,3,5,6};
    intersect(arr1,arr2,5,4);
    uni(arr1,arr2,5,4);
    return 0;
}
