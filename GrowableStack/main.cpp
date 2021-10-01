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
        length = 3;
        growth = 3;
        arr = new T[3];
    }

    GrowableStack(int c) {
        top = -1;
        length = c;
        growth = c;
        arr = new T[c];
    }
    void grow_stack();
    void push(T val);
    T pop();
    T peek();
    void display();
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

//Function to check if the given string is a palindrome (using stack)
bool is_palindrome(string s) {
    int len = s.length();
    int mid = len/2;

    GrowableStack<char> st;
    int i;
    //push first half characters of string onto stack
    for (i=0; i<mid; i++)
        st.push(s[i]);

    if (len % 2 !=0)
        i++;

    //compare the remaining elements with the elements of stack
    for (; i<len; i++)
    {
        if (st.pop() != s[i])
            return false;
    }
    return true;
}

//DRIVER CODE
int main() {

    cout<<"1. Implement stack operations \n2. Check palindrome \nEnter choice: ";
    int choice;
    cin>>choice;
    switch(choice) {
        case 1:
            int c;
            cout<<"Enter the value by which stack should grow: ";
            cin>>c;
            if (c>0) {
                GrowableStack<int> s1(c);
                while (true) {
                    cout << "\nMENU: \n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Quit \nEnter Choice: ";
                    int choice1;
                    cin >> choice1;
                    switch (choice1) {
                        case 1:
                            int val;
                            cout<<"Enter value to be pushed : ";
                            cin>>val;
                            s1.push(val);
                            break;

                        case 2:
                            cout<<"Popped item : "<<s1.pop()<<endl;
                            break;

                        case 3:
                            cout<<"Top item : "<<s1.peek()<<endl;
                            break;

                        case 4:
                            cout<<"Stack:\n";
                            s1.display();
                            break;

                        case 5:
                            exit(0);

                        default: cout<<"Invalid Choice!";
                    }
                }
            }
            else {
                cout<<"value must be greater than zero!\n";
            }
            break;

        case 2:
            string str1;
            cout<<"Enter String: ";
            cin>>str1;
            if (is_palindrome(str1))
                cout<<"String is palindrome.\n";
            else
                cout<<"String is not a palindrome.\n";
    }

    return 0;
}
