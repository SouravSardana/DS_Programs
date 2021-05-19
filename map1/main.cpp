#include <iostream>
#include <map>
using namespace std;
void count_freq(int arr[],int n)
{
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(auto x:m)
        cout<<x.first<<"->"<<x.second<<endl;
}
int main()
{
    int arr[] = {10,12,10,15,10,20,12,12};
    count_freq(arr,8);
    return 0;
}
