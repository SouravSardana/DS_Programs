//Stack using stl
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack <int> s;
    cout<<s.empty()<<endl;
    s.push(5); //insert
    s.push(10);
    s.pop(); //delete
    cout<<s.top()<<endl; //peek
    s.push(15);
    cout<<s.size();
    return 0;
}
