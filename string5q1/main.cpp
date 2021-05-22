/*Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . .
. j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same
backwards. More formally, S is palindrome if reverse(S) = S. In case of conflict, return
the substring which occurs first ( with the least starting index).*/
#include <iostream>

using namespace std;
bool CheckPalin(string s)
{
    int i=0;
    int j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    string s="aabbbac";
    int i=0;
    int maxi=0;
    string res="";
    while(i<s.length())
    {
        int j=s.length();
        while(j>i)
        {
            string temp=s.substr(i,j-i);
            if(CheckPalin(temp))
            {
                if(temp.length()>maxi)
                {
                    res=temp;
                    maxi=temp.length();
                }
                break;
            }
            j--;
        }
        i++;
    }
    cout<<res;
    return 0;
}
