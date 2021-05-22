/*Write a function to find the longest common prefix string amongst
an array of strings. If there is no common prefix, return an empty
string "".*/
#include <iostream>

using namespace std;
string func(string arr[],int n)
{
    int counter;
    int mi=INT_MAX;
    if(n==0)
        return "";
    string s=arr[0];
    if(n==1)
        return s;
    for(int i=1;i<n;i++)
    {
        int j=0;
        counter=0;
        while(j<s.size() && j<n)
        {
            if(s[j]==arr[i][j])
                counter++;
            else
                break;
            j++;
        }
        mi=min(mi,counter);
    }
    return s.substr(0,mi);
}
int main()
{
    string arr[]={"flower","flow","flight"};
    cout<<func(arr,3);
    return 0;
}
