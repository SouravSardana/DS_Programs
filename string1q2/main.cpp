#include <bits/stdc++.h>

using namespace std;

void print_dup(string s)
{
    map <char,int> m;
    for(int i=0;i<s.length();i++)
        m[s[i]]++;
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second > 1)
        {cout<<it->first<<"->"<<it->second;
        cout<<endl;}
    }
}
int main()
{
    string s = "geeksforgeeks";
    print_dup(s);
    return 0;
}
