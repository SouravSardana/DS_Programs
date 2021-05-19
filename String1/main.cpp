#include <iostream>

using namespace std;

int main()
{
    string str = "abcdaa";
    int counter[256] = {0};
    int index=-1;
    for(int i=str.length()-1;i>=0;i--)
    {
        counter[str[i]]++;
        if(counter[str[i]]>1)
            index=i;
    }
    cout<<index;
    return 0;
}
