//
// Created by TaniaAggarwal on 5/24/2021.
//

#ifndef STUDENTDICTIONARY_STUDENT_H
#define STUDENTDICTIONARY_STUDENT_H

#include <string>
using namespace std;

class Student {
    string rollno;
    string name;
    string address;
    string dob;
public:
    Student(string, string, string, string);
    Student();
    void print_data();
    string get_key();
    string get_name();
    string get_address();
    string get_dob();

    void set_key(string key);
};


#endif //STUDENTDICTIONARY_STUDENT_H
