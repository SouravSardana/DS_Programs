#include <iostream>
using namespace std;

/*
 * Growable stack
 * Implemented using Tight Strategy
 * */
template <class T>
class GrowableStack {
    int top;
    int length;
    T* arr;
    int growth;

public:
    GrowableStack() {
        top = -1;
        length = 0;
        growth = 3;
        arr = new T[3];
    }

    GrowableStack(int c) {
        top = -1;
        length = 0;
        growth = c;
        arr = new T[c];
    }
    void grow_stack();
    void push(T val);
    T pop();
    T peek();
    void display();
    bool is_empty();
};

//function to grow stack by given length
template <class T>
void GrowableStack<T> :: grow_stack() {

    //create new array with increased size
    T* new_arr = new T[length + growth];

    //copy the elements from previous array
    for (int i=0; i<length; i++)
        new_arr[i] = arr[i];

    length += growth; //increase the length
    free(arr); //free up space of previous array
    arr = new_arr; //update pointer to new array
}

//function to add element at the top of stack
template <class T>
void GrowableStack<T> :: push(T val) {
   if (top == length-1)
       grow_stack();

   arr[++top] = val;
}

//function to remove element from top and return the removed element
template <class T>
T GrowableStack<T> :: pop() {
    if (top >= 0) {
        T item = arr[top];
        top--;
        return item;
    }
    return -1;
}

template <class T>
T GrowableStack<T> :: peek() {
    if (top >= 0) {
        return arr[top];
    }
    return 0;
}

//function to display elements of stack
template <class T>
void GrowableStack<T> :: display() {
    if (top == -1) {
        cout<<"Stack is Empty!";
    }
    else {
        for (int i=0; i<=top; i++)
            cout<<arr[i]<<endl;
    }

}

template <class T>
bool GrowableStack<T> ::is_empty() {
    if (top == -1)
        return true;
    return false;
}