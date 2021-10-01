#include<bits/stdc++.h>
using namespace std; 
string upperLower(string str)
	{
         for(int i=0;i<str.length();i++)
        {
            if(int(str[i])>=65 && int(str[i])<=91)
            str[i]=str[i]+32;
        }
        return str;
    }
    
int main()
{
	string s;
	cin>>s;
    cout<<upperLower(s);
	return 0;
}  
