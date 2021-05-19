//Print all permutations of a string
#include <iostream>

using namespace std;

void swap(char *x, char *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void perm(string S,int l,int r)
{
    if(l==r)
        cout<<S<<" ";
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(S[l],S[i]);
            perm(S,l+1,r);
            swap(S[l],S[i]);
        }
    }
}
int main()
{
    perm("ABC",0,2);
    return 0;
}
