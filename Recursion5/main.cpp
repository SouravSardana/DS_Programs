// nth number of fibonacci series
#include <iostream>

using namespace std;
long long int nthFibonacci(long long int n){
        // code here
        if(n==0 || n==1)
            return n;
        return (nthFibonacci(n-1) + nthFibonacci(n-2));
    }

int main()
{
    cout<<nthFibonacci(9);
    return 0;
}
