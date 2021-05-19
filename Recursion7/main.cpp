//Sum of digits of a number.
#include <iostream>

using namespace std;
int SumOfDigits(int num)
{
    if(num<10)
        return num;
    return SumOfDigits(num/10) + num%10;
}
int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<SumOfDigits(num);
    return 0;
}
