/*Print Anagrams Together
Given an array of strings, return all groups of strings that are anagrams. The groups
must be created in order of their appearance in the original array. Look at the sample
case for clarification.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list)
{
    // Your Code Here
    vector<vector<string>> v;
    vector<string> d;
    unordered_map<string,vector<string>> m;
    for(int i=0;i<string_list.size();i++)
    {
        vector<string> d;
        string s=string_list[i];
        sort(s.begin(),s.end());
        for(int j=0;j<string_list.size();j++)
        {
            string s1=string_list[j];
            sort(s1.begin(),s1.end());
            if(s==s1)
                d.push_back(string_list[j]);
        }
        m[s]=d;
    }
    for(auto x:m)
    {
        v.push_back(x.second);
    }
    return v;
}
int main()
{
    vector<string> v={"act","god","cat","dog","tac"};

    vector<vector<string>> s;
    s=Anagrams(v);
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s[i].size();j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
