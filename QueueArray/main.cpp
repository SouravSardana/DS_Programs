//If we use array, then insertion at end(enqueue) will take O(1)
//but deletion from beginning(dequeue) will take O(n).
//Therefore we use circular Array so that both operations can be performed in O(1)
#include <iostream>

using namespace std;
class Queue
{
    int frontE, rear;
    int capacity;
    int *arr;
    public:
    Queue()
    {
        frontE=-1;
        rear=-1;
        capacity=5;
        arr=new int[capacity];
    }
    void enqueue(int val);
    void print_queue();
    int dequeue();
    bool isEmpty();
    int front_element();
    int rear_element();
};
void Queue::enqueue(int val)
{
    if((frontE==0 && rear==capacity-1) || rear == frontE-1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    else if(frontE==-1)
    {
        frontE++;
        rear++;
        arr[rear]=val;
    }
    else
    {
        rear=(rear+1)%capacity;
        arr[rear]=val;
    }
}
void Queue::print_queue()
{
    if(frontE==-1)
    {
        cout<<"Empty"<<endl;
        return;
    }
    if(frontE<=rear){
    for(int i=frontE;i<=rear;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    }
    else
    {
        for(int i=frontE;i<capacity;i++)
            cout<<arr[i]<<" ";
        for(int i=0;i<=rear;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}
int Queue::dequeue()
{
    if(frontE==-1)
    {
        cout<<"Queue is empty"<<endl;
        return INT_MIN;
    }
    else
    {
        int item=arr[frontE];
        arr[frontE]=-1;
        if(frontE==rear)
        {
            frontE=-1;
            rear=-1;
        }
        else
            frontE = (frontE+1)%capacity;
        return item;
    }
}
bool Queue::isEmpty()
{
    if(frontE==-1)
        return true;
    return false;
}
int Queue::front_element()
{
    return arr[frontE];
}
int Queue::rear_element()
{
    return arr[rear];
}
int main()
{
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(5);
    cout<<q.isEmpty()<<endl;
    q.enqueue(8);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print_queue();
    cout<<q.dequeue()<<endl;
    q.print_queue();
    cout<<q.front_element()<<" "<<q.rear_element()<<endl;
    q.enqueue(9);
    q.print_queue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print_queue();
    q.enqueue(11);
    q.dequeue();
    q.print_queue();
    q.dequeue();
    q.dequeue();
    q.print_queue();
    return 0;
}
