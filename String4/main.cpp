//Urlify given string where spaces are changed with %20
#include <iostream>

using namespace std;

string urlify(string str, int l)
{
    string res="";
    for(int i=0;i<l;i++)
    {
        if(str[i]==' ')
            res+="%20";
        else
            res+=str[i];
    }
    return res;
}
int main()
{
    string str = "Mr John Smith   ";
    cout<<urlify(str,13);
    return 0;
}
