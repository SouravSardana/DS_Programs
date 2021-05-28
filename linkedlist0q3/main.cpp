#include <iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
class SinglyLinkedList
{
    Node* head;
    public:
    SinglyLinkedList()
    {
        head=nullptr;
    }
    void traverse();
    void insert_at_end(int val);
    int pos(int item);
};
void SinglyLinkedList::insert_at_end(int val)
{
    Node* newNode = new Node;
    newNode->data=val;
    newNode->next=nullptr;
    if(head==nullptr)
    {
        head=newNode;
        return;
    }
    Node *temp= head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next = newNode;
}
void SinglyLinkedList::traverse()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int SinglyLinkedList::pos(int item){

        //Code here
        int counter=-1;
        Node* current = head;
        while(current!=NULL)
        {
            counter++;
            if(current->data==item)
                return counter;
            current=current->next;
        }
        return -1;
}
int main()
{
    SinglyLinkedList l1;
    l1.insert_at_end(2);
    l1.insert_at_end(4);
    cout<<l1.pos(4)<<endl;
    cout<<l1.pos(5);
    return 0;
}
