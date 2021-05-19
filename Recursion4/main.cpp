//Factorial in tail recursive
#include <iostream>

using namespace std;

int fact(int n, int val=1)
{
    if(n==0||n==1)
        return val;
    return fact(n-1,n*val);
}
int main()
{
    cout<<fact(5);
    return 0;
}
