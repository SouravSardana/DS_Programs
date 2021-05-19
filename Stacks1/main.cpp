#include <iostream>

using namespace std;
class stackImp
{
    int top;
    int capacity;
    int *arr;
    int GrowFactor;
public :
    stackImp()
    {
        top=-1;
        capacity=0;
        GrowFactor=3;
        arr = new int[GrowFactor];
    }
    void grow();
    void push(int val);
    void printStack();
    void peek();
    int pop();
    bool isempty();
};
void stackImp::grow()
{
    int* temp = new int[capacity+GrowFactor];
    for(int i=0;i<capacity;i++)
        temp[i]=arr[i];
    delete arr;
    arr=temp;
    capacity+=GrowFactor;
}
void stackImp::push(int val)
{
    if(top==capacity-1)
        grow();
    top++;
    arr[top]=val;
}
void stackImp::printStack()
{
    for(int i=0;i<=top;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void stackImp::peek()
{
    cout<<arr[top]<<endl;
}
int stackImp::pop()
{
    if(top==-1){
        cout<<"No element in stack"<<endl;
        return -1;
    }
    else
    {
        int item = arr[top];
        top--;
        return item;
    }
}
bool stackImp::isempty()
{
    if(top==-1)
        return true;
    return false;
}
int main()
{
    stackImp s;
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.printStack();
    s.peek();
    cout<<s.pop();
    cout<<endl;
    s.printStack();
    cout<<s.isempty();
    return 0;
}
