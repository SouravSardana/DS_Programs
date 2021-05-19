#include <iostream>
#include <math.h>
using namespace std;
double OneByTwo(int k)
{
    if(k==0)
        return 1;
    return((double)1/pow(3,k)+OneByTwo(k-1));
}
int main()
{
    cout<<OneByTwo(3);
    return 0;
}
