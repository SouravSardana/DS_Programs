#include<bits/stdc++.h>
using namespace std;

int immediateGreater(int arr[], int n, int x)
{
        int mini=INT_MAX;
    int index=-1;
    int flag=0;
  
    for(int i=0;i<n;i++)
    {
        if(arr[i]>x)
        {
            if(abs(arr[i]-x)<mini)
            {
                mini=abs(arr[i]-x);
                index=i;
                flag=1;
            }
        }
     
    }
         if(flag==1)
         return arr[index]; 
         else
         return -1;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int x;
	cin>>x;
	cout<<immediateGreater(arr,n,x);
	return 0;
}
