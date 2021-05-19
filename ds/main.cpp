#include <iostream>

using namespace std;
string reverseWords(string s) {
        string str="";
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==32)
            {
                if(str.length()==0)
                    str+=temp;
                else
                    str=temp+" "+str;
                temp="";
            }
            else
                temp+=s[i];
        }
        if(s[s.size()-1] != 32)
            str=temp+" "+str;
        return str;
    }
int main()
{
    cout<<reverseWords(" hello world ");
    return 0;
}
