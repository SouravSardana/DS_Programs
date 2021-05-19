//Print all subsets of a string (in any order)
#include <iostream>

using namespace std;

void subset(string str,string cur="",int index=0)
{
    if(index==str.length())
    {
        cout<<cur<<" ";
        return;
    }
        subset(str,cur,index+1);
        subset(str,cur+str[index],index+1);
}

int main()
{
    subset("ABC");
    return 0;
}
