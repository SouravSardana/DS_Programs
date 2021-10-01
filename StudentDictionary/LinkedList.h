//
// Created by TaniaAggarwal on 5/24/2021.
//
#include <iostream>
#include "Student.h"
using namespace std;

class Node{
public:

    Student data;
    Node* next;
    Node(Student data) : data(data) {
        next = nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList()
    {
        head = nullptr;
    }
//    bool search_list(T val);
//    void insert_at_head(T val);
//    void remove_from_list(string val);
};

//template <class T>
//bool LinkedList<T> :: search_list(T val)
//{
//    Node<T>* temp = head;
//    while(temp != NULL)
//    {
//        if (temp->data == val)
//            return true;
//        temp = temp->next;
//    }
//    return false;
//}
//
//template <class T>
//void LinkedList<T>::insert_at_head(T val) {
//    // make a new node
//    Node<T>* new_node = new Node<T>;
//    new_node->data = val;
//    new_node->next = NULL;
//
//    if (head == NULL)
//        head = new_node;
//    else
//    {
//        new_node->next = head;
//        head = new_node;
//    }
//}
//
//template <class T>
//void LinkedList<T>::remove_from_list(string val) {
//    //if head is to be deleted
//    if (head->data == val)
//    {
//        Node<T>* temp;
//        temp = head->next;
//        delete head;
//        head = temp;
//        return;
//    }
//
//    Node<T>* temp = head;
//    while(temp->next != NULL)
//    {
//        if (temp->next->data == val)
//        {
//            Node<T>* temp_ptr = temp->next->next;
//            delete temp->next;
//            temp->next = temp_ptr;
//            return;
//        }
//        temp = temp->next;
//    }
//    cout<<"Value not found!\n";
//}
