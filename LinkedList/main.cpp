#include <iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
class LinkedList
{
    Node* head;
public:
    LinkedList()
    {
        head=NULL;
    }
    void insert_at_beg(int val);
    void printLL();
    void insert_at_end(int val);
};
void LinkedList::insert_at_beg(int val)
{
    Node* newNode = new Node;
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}
void LinkedList::printLL()
{
    Node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void LinkedList::insert_at_end(int val)
{
    Node* newNode = new Node;
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        Node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
}
int main()
{
    LinkedList l1;
    l1.insert_at_beg(3);
    l1.insert_at_beg(5);
    l1.insert_at_end(6);
    l1.printLL();
    return 0;
}
