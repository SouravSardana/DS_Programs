#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int,int> m;
    int arr[]={0,7,2,5,4,7,1,3,6};
    for(int i=0;i<9;i++)
    {
        m[arr[i]]++;
        if(m[arr[i]]==2)
        {
            cout<<arr[i];
            break;
        }
    }
    return 0;
}
