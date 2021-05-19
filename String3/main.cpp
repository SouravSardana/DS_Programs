//Pattern matching in O(n) using KMP algorithm
#include <bits/stdc++.h>
using namespace std;

void generate_lps(char *pat,int m,int *lps)
{
    lps[0]=0;
    int len =0;
    int i=1;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
                len = lps[len-1];
            else
            {
                lps[i]=len;
                i++;
            }
        }
    }
}
void pattern_match(char* txt, char* pat)
{
    int n=strlen(txt);
    int m=strlen(pat);
    int lps[m]; //longest proper prefix which is also suffix
    generate_lps(pat,m,lps);
    int i=0;
    int j=0;
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"pattern found at index "<<i-j;
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
}

int main()
{
    char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";
    pattern_match(txt,pat);
    return 0;
}
