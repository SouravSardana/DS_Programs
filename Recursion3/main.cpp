//printing numbers from 1 to n using tail recursion.
#include <iostream>

using namespace std;

void print_num(int n, int k=1)
{
    if(n==0)
        return;
    cout<<k<<endl;
    print_num(n-1,k+1);
}

int main()
{
    print_num(5);
    return 0;
}
