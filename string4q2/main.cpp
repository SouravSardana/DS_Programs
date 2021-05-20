/*Check if a string is a valid shuffle of two other strings
1XY2 is a valid shuffle of XY and 12
Y12X is not a valid shuffle of XY and 12*/
#include <iostream>

using namespace std;

int main()
{
    string s1="xy";
    string s2 = "12";
    string s3 = "1xy2";
    if(s3.length() != s1.length() + s2.length())
    {
        cout<<"No";
        return 0;
    }
    int i=0,j=0,k=0;
    while(k<s3.length())
    {
        if(i<s1.length() && s3[k]==s1[i])
        {
            i++;
            k++;
        }
        else if(j<s2.length() && s3[k]==s2[j])
        {
            j++;
            k++;
        }
        else
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
