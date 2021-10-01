#include<bits/stdc++.h>
using namespace std;

string missingPanagram(string str)
{
    bool arr[26]={0};
    int index;
    string ans="";
    int flag=0;
    for (int i = 0; i < str.length(); i++) 
    {
        if ('A' <= str[i] && str[i] <= 'Z')
          index = str[i] - 'A';
        else if ('a' <= str[i] && str[i] <= 'z')
            index = str[i] - 'a';
        else
            continue;
        arr[index] = 1;
    }
    for(int i=0;i<26;i++)
    {
    if(arr[i] != 1)
    {
    flag=1;    
    ans=ans+(char)(i+'a');
    }
    }
    if(flag==0)
    return "-1";
    else
    return ans;
        
}

int main()
{
	string s;
	cin>>s;
    cout<<missingPanagram(s);
	return 0;
}
