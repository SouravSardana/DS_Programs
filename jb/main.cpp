#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

string transform(string S){
    //transform(S.begin(), S.end(), S.begin(), ::tolower);

    char ch=S[0];
    string s2="";
    int count=1;
    int i=0;

    for(i=1;i<=S.length();i++)
    {

        if(S[i]=='\0')
        {
           s2 = s2 + to_string(count) +ch;
        }
        else if(S[i]==ch)
        {
            count++;
        }
        else
        {
            s2 = s2 + to_string(count) +ch;
            ch=S[i];
            count=1;
        }
    }
     S=s2;
     return S;


}

int main()
{
	string str="aaaaAABBccc";
	cout<<transform(str);
}
