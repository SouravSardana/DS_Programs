#include<bits/stdc++.h>
using namespace std; 
string lowerUpper(string str)
	{
        
        for(int i=0;i<str.length();i++)
        {
            if(int(str[i])>=97 && int(str[i])<=122)
            str[i]=str[i]-32;
        }
        return str;
    }
    
int main()
{
	string s;
	cin>>s;
    cout<<lowerUpper(s);
	return 0;
}    
