#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    string str;
    for(int i=0;i<s.length();i++)
    {
        int  j=1;
        while(s[i+j-1]!='\0')
        {
            str = s.substr(i,j);
            cout<<str<<" ";
            j++;
        }
    }
    return 0;
}
