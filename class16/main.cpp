#include <iostream>

using namespace std;

void RemoveChar(string &s, char c)
{
        string str="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=c)
                str+=s[i];
        }
        s=str;
}
int main()
{
    string s;
    char c;
    cin>>s;
    cin>>c;
    RemoveChar(s,c);
    cout<<s;
    return 0;
}
