// String palindrome using recursion
#include <iostream>

using namespace std;

bool palin(string str,int s, int e)
{
    if(s>e)
        return true;
    if(str[s]!=str[e])
        return false;
    return palin(str,s+1,e-1);
}
int main()
{
    cout<<palin("naman",0,4);
    return 0;
}
