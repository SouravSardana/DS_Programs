#include <iostream>

using namespace std;
void red(string input,string output)
{
    if(input.size()==0)
    {
        cout<<output<<endl;
        return;
    }
    red(input.substr(1),output);
    red(input.substr(1),output+input[0]);
}
void print_subseq(string str)
{
    red(str,"");
}
int main()
{
    print_subseq("aaa");
    return 0;
}
