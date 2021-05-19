//printing numbers from 1 to n using recursion.
#include <iostream>

using namespace std;

void print_num(int n)
{
    if(n==0)
        return;
    print_num(n-1);
    cout<<n<<endl;
}

int main()
{
    print_num(5);
    return 0;
}
