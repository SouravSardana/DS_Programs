#include <iostream>

using namespace std;
/* MY METHOD
bool checkOrder(int arr[],int n)

    int flag=0;
    for(int i=0;i<n-2;i++)
    {
        if((arr[i+1]-arr[i])*(arr[i+2]-arr[i+1]) < 0)
            flag++;
    }
    if(flag<=1)
        return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(checkOrder(arr,n))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
*/
// Sir's Method
int main()
{
    int n,x,y,prev;
    cin>>n;
    cin>>x;
    prev=x;
    bool isDec=true;
    for(int i=1;i<=n-1;i++)
    {
        cin>>y;
        if(y>prev)
            isDec =false;
        else if(y<prev)
        {
            if(isDec==false)
            {
                cout<<"false";
                return 0;
            }
        }
        else
        {
            cout<<"false";
            return 0;
        }
        prev=y;
    }
    cout<<"true";
    return 0;
}
