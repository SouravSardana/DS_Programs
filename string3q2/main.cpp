#include <bits/stdc++.h>

using namespace std;
string secRep(string arr,int n)
{
    unordered_map<string,int> m;
    auto it=m.begin();
    int maxi=it->second;
    int sec_max=maxi;
    string str;
    for(auto it = m.begin();it!=m.end();it++)
    {
        if(it->second<maxi && sec_max==maxi)
        {
            sec_max = it->second;
            str=it->first;
        }
        else if(it->second<maxi && it->second>sec_max)
        {
            sec_max = it->second;
            str=it->first;
        }

    }
    return str;
}
int main()
{
    string arr[]={"aaa","bbb","ccc","bbb","aaa","aaa"};
    unordered_map<string,int> m;
    for(int i=0;i<6;i++)
        m[arr[i]]++;
    int maxi=INT_MIN;
    int sec_max=INT_MIN;
    for(auto x:m)
    {
        if(x.second>maxi)
        {
            sec_max=maxi;
            maxi=x.second;
        }
        else if(x.second>sec_max && x.second<maxi)
            sec_max=x.second;
    }
    for(auto x:m)
    {
        if(x.second==sec_max)
            cout<<x.first;
    }
}
