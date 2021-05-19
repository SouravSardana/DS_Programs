#include <iostream>

using namespace std;
bool rot(string s1,string s2)
{
    if(s1.length()!=s2.length())
            return false;
    s1+=s1;
    if(s1.find(s2)!=string::npos)
        return true;
    return false;
}
int main()
{
    string str1="ABACD";
    string str2="CDABA";
    cout<<rot(str1,str2);
    return 0;
}
