// One away
#include <bits/stdc++.h>

using namespace std;

bool check(string s1, string s2)
{
    int counter[256]={0};
    int counter_minus = 0, counter_one =0;
    int diff=s1.size()-s2.size();
    if(diff>=2 || diff<=-2)
        return false;
    for(int i=0;i<s1.size();i++)
        counter[s1[i]]++;
    for(int i=0;i<s2.size();i++)
        counter[s2[i]]--;
    for(int i=0;i<256;i++)
    {
        if(counter[i]<-1 || counter[i]>1)
            return false;
        if(counter[i]==-1)
            counter_minus++;
        else if(counter[i]==1)
            counter_one++;
        if(counter_one>=2 || counter_minus>=2)
            return false;
    }
    return true;
}
int main()
{
    string str2,str1;
    cout << "Enter a string: ";
    cin>>str1;
    cout<<"Enter another string: ";
    cin>>str2;
    cout<<check(str1,str2);
    return 0;
}
