// Linked list
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
    void insert_at_beg(int val);
    void insert_at_pos(int pos_val,int val);
    void delete_from_beg();
    void delete_from_end();
    void delete_from_pos(int item);
};
void SinglyLinkedList::insert_at_beg(int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head=newNode;
}
void SinglyLinkedList::insert_at_end(int val)
{
    Node* newNode = new Node;
    newNode->data=val;
    newNode->next=nullptr;
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
void SinglyLinkedList::insert_at_pos(int pos_val,int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    Node* temp=head;
    while(temp!=NULL && temp->data != pos_val)
        temp=temp->next;
    if(temp==nullptr)
    {
        cout<<"item not found";
        return;
    }
    newNode->next=temp->next;
    temp->next = newNode;
}
void SinglyLinkedList::delete_from_beg()
{
    if(head==nullptr)
    {
        cout<<"List is empty";
        return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
}
void SinglyLinkedList::delete_from_end()
{
    if(head==nullptr)
    {
        cout<<"List is empty";
        return;
    }
    Node* temp=head->next;
    Node* save =head;
    if(temp==nullptr)
    {
        head=nullptr;
        delete save;
        return;
    }
    while(temp->next!=nullptr)
    {
        save=temp;
        temp=temp->next;
    }
    save->next=NULL;
    delete temp;
}
void SinglyLinkedList::delete_from_pos(int item)
{
    if(head==nullptr)
    {
        cout<<"List is empty";
        return;
    }
    if(head->data==item)
    {
        Node* ptr = head;
        head=head->next;
        delete ptr;
    }
    Node* save = head;
    Node* temp= head->next;
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            save->next=temp->next;
            delete temp;
            return;
        }
        save=temp;
        temp=temp->next;
    }
    cout<<"item does not exist";

}
int main()
{
    SinglyLinkedList l1;
    l1.insert_at_beg(5);
    l1.insert_at_beg(4);
    l1.insert_at_end(1);
    l1.insert_at_end(2);
    l1.insert_at_pos(4,3);
    l1.traverse();
    cout<<endl;
    l1.delete_from_beg();
    l1.traverse();
    cout<<endl;
    //l1.insert_at_pos(6,2); item not found will be printed
    l1.delete_from_end();
    l1.traverse();
    cout<<endl;
    l1.delete_from_pos(5);
    l1.traverse();
    return 0;
}
