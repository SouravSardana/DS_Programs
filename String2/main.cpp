#include <iostream>

using namespace std;
bool aresame(int counter1[],int counter2[])
{
    for(int i=0;i<256;i++)
    {
        if(counter1[i]!=counter2[i])
            return false;
    }
    return true;
}

int main()
{
    string s1,s2;
    cout<<"Enter text String s1: ";
    cin>>s1;
    cout<<"Enter pattern string s2: ";
    cin>>s2;
    int counter1[256]={0};
    int counter2[256]={0};
    for(int i=0;i<s2.length();i++)
    {
        counter1[s1[i]]++;
        counter2[s2[i]]++;
    }
    for(int i=s2.length();i<s1.length();i++)
    {
        if(aresame(counter1,counter2))
        {
            cout<<"YES";
            return 0;
        }
        counter1[s1[i-s2.length()]]--;
        counter1[s1[i]]++;
    }
    cout<<"NO";
    return 0;
}
