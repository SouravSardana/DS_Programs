// Remove duplicacy of characters in a string using hash map
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char,int> m;
    string s = "nagarro";
    for(int i=0;i<s.length();i++)
        m[s[i]]++;
    for(auto x:m)
        cout<<x.first;
    return 0;
}
