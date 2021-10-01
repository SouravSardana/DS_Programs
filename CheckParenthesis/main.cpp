#include "GrowableStack.h"
#include <iostream>
#include <string>
using namespace std;

bool check_parenthesis(string s) {

    //create a stack
    GrowableStack<char> st;

    //iterate over the input string
    for(int i=0; i<s.length(); i++) {

        //if opening parenthesis is encountered, push it to stack
        if (s[i] == '{')
            st.push(s[i]);

        // if closing brace is encountered, pop from stack
        // if stack is empty, return false
        else if (s[i] == '}') {
            if (st.is_empty())
                return false;
            st.pop();
        }
    }
    // once the whole string has been iterated, if the stack becomes empty, return true
    // else return false
    if (st.is_empty())
        return true;
    return false;
}

int main() {

    string temp;
    string input = "";
    cout<<"Enter input code:\n";

    // read input until empty line is encountered
    // keep appending the input taken to string variable 'input'
    while(getline(cin, temp)) {
        if (temp.empty())
            break;
        input.append(temp);
    }

    //function call to check if parenthesis are balanced
    if (check_parenthesis(input))
        cout<<"Parenthesis are balanced!\n";
    else
        cout<<"Parenthesis are not balanced!\n";

    return 0;
}
