/*Given a binary string, that is it contains only 0s and 1s. We need to make this string a
sequence of alternate characters by flipping some of the bits, our goal is to minimize
the number of bits to be flipped.*/
#include <iostream>

using namespace std;

int main()
{
    string S="0001010111";
    int c1=0,c2=0;
    for(int i=0;i<S.length();i++)
    {
        if(i%2==0)
        {
            if(S[i]=='0')
                c2++;
            else
                c1++;
        }
        else
        {
            if(S[i]=='1')
                c2++;
            else
                c1++;
        }
    }
    cout<< min(c1,c2);
    return 0;
}
