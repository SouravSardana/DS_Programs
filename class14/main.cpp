#include <iostream>
#include <unordered_map>
using namespace std;
    char getMaxOccuringChar(string str)
    {
        // Your code
        //freq=0,
        int index;
        unordered_map <char,int> m;
        for(int i=0;i<str.length();i++)
        {
            m[str[i]]++;
        }
        int maxi=0;
        for(int i=0;i<str.length();i++)
        {
            if(m[str[i]]>maxi)
            {
                index=i;
                maxi = m[str[i]];
            }
        }
        return str[index];
    }
    int main()
    {
        string s="xy";
        cout<<getMaxOccuringChar(s);
        return 0;
    }
