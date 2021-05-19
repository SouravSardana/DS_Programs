#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    string s;
    int counter=1;
    string str="";
    cin>>s;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1])
            counter++;
        else
        {
            if(counter!=1)
                str+= s[i-1]+ to_string(counter);
            else
                str+= s[i-1];
            counter=1;
        }
    }
    if(counter!=1)
        str+=s[s.length()-1]+to_string(counter);
    else
        str+= s[s.length()-1];
    cout<<str;
    return 0;
}
