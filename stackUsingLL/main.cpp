//Stacks using Linked List
#include <iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
class StackLL
{
    Node* head;
    Node* top;
public:
    StackLL()
    {
        head=nullptr;
        top=head;
    }
    void push(int val);
    void print_stack();
    int peek();
    int pop();
    bool isEmpty();
};
void StackLL::push(int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next=head;
    head=newNode;
    top=head;
}
void StackLL::print_stack()
{
    Node* ptr=top;
    while(ptr!=nullptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
int StackLL::peek()
{
    return top->data;
}
int StackLL::pop()
{
    if(head==nullptr)
    {
        cout<<"empty stack"<<endl;
        return -1;
    }
    Node* ptr=head;
    int item=head->data;
    head=head->next;
    top=head;
    delete ptr;
    return item;
}
bool StackLL::isEmpty()
{
    if(top==NULL)
        return true;
    return false;
}
int main()
{
    StackLL s;
    cout<<s.isEmpty()<<endl;
    s.push(3);
    s.push(6);
    s.push(8);
    s.print_stack();
    cout<<s.pop()<<endl;
    s.print_stack();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
}
