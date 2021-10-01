//
// Created by TaniaAggarwal on 5/24/2021.
//
#include <iostream>
#include "Student.h"
using namespace std;

class Student;

Student ::Student() {
    rollno = name = address = dob = "";
}

Student ::Student(string roll_no, string s_name, string s_address, string s_dob) {
    rollno = roll_no;
    name = s_name;
    address = s_address;
    dob = s_dob;
}

void Student ::print_data() {
    cout<<"rollno: "<<rollno<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"address: "<<address<<endl;
    cout<<"dob: "<<dob<<endl;
}

string Student ::get_key() {
    return rollno;
}

string Student::get_name() {
    return name;
}

string Student::get_address() {
    return address;
}

string Student::get_dob() {
    return dob;
}

void Student::set_key(string key) {
    rollno = key;
}
