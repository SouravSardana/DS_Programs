#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int row,col;
        cin>>row>>col;
        int arr[row][col];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                cin>>arr[i][j];
        }
        for(int j=0;j<col;j++)
        {
            for(int i=0;i<row;i++)
            {
                if(j%2==0)
                    cout<<arr[i][j]<<" ";
                else
                    cout<<arr[row-i-1][j]<<" ";
            }
        }
    }
    return 0;
}
