/*Isomorphic Strings
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each
other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping
possible for every character of str1 to every character of str2 while preserving the
order.
Note: All occurrences of every character in ‘str1’ should map to the same character in
‘str2’
*/
#include <bits/stdc++.h>

using namespace std;
bool isIsomorphic(string s, string t) {
    map<char,char> m1;
    map<char,char> m2;
    if(s.length()!=t.length())
        return false;
    for(int i=0;i<s.length();i++)
    {
        auto it=m1.find(s[i]);
        if(it==m1.end())
        {
            m1[s[i]]=t[i];
        }
        else
        {
            if(it->second != t[i])
                return false;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        auto it=m2.find(t[i]);
        if(it==m2.end())
        {
            m2[t[i]]=s[i];
        }
        else
        {
            if(it->second != s[i])
                return false;
        }
    }
    return true;
}
int main()
{
    cout << isIsomorphic("aab","xxy")<<endl;
    cout << isIsomorphic("foo","bar");
    return 0;
}
