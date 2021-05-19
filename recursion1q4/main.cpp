#include <iostream>

using namespace std;

bool func(string s,int start,int ending)
{
    if(s[start]!=s[ending])
        return false;
    if(start>=ending)
        return true;
    return(func(s,start+1,ending-1));
}

bool palin(string s)
{
    int i=0,l=0;
    while(s[i]!='\0')
    {
        l++;
        i++;
    }
    int start=0, ending=l-1;
    return(func(s,start,ending));
}
int main()
{
    string s="rajarshree";
    cout<<palin(s);
    return 0;
}
