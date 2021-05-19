#include <bits/stdc++.h>

using namespace std;
bool palin(string s)
{
    int beg=0;
    int ending=s.length()-1;
    while(beg<ending)
    {
        if(s[beg]!=s[ending])
            return false;
        beg++;
        ending--;
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    cout<<palin(s);
    return 0;
}
