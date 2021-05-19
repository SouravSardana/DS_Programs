// Cut a rope in maximum pieces such that size of each piece is either a or b or c
#include <iostream>

using namespace std;
int MaxCuts(int l,int a,int b,int c)
{
    if(l==0)
        return 0;
    if(l<0)
        return -1;
    int res = max(max(MaxCuts(l-a,a,b,c),MaxCuts(l-b,a,b,c)),MaxCuts(l-c,a,b,c));
    if(res==-1)
        return -1;
    return res+1;
}

int main()
{
    cout << MaxCuts(5,2,1,5);
    return 0;
}

