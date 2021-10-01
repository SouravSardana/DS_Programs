//
// Created by TaniaAggarwal on 5/24/2021.
//

#include "Chaining.h"
#include "HashFunctions.h"
#include <iostream>
using namespace std;

class Chaining;

Chaining :: Chaining(int n) {
    int prime = nextPrime(n);
    array_size = prime;
    table = new LinkedList[array_size];
}

int Chaining::hash(int key) {
    return (key % array_size);
}

void Chaining::ch_insert(Student s, int key) {
    lookups = 1;
    string s_key = s.get_key();
    int index = hash(key);

    auto* new_node = new Node(
            Student(s.get_key(), s.get_name(), s.get_address(), s.get_dob()));
    new_node->data = s;
    new_node->next = nullptr;

    if (table[index].head == nullptr) {
        table[index].head = new_node;
    } else {
        new_node->next = table[index].head;
        table[index].head = new_node;
    }
}

void Chaining :: ch_remove(string s_key, int key) {
    lookups = 0;
    int index = hash(key);

    if (table[index].head->data.get_key() == s_key) {
        lookups = 1;
        Node* t = table[index].head->next;
        delete table[index].head;
        table[index].head = t;
        return;
    }
    Node* temp = table[index].head;
    while (temp != nullptr) {
        lookups++;
        if (temp->next->data.get_key() == s_key) {
            Node* t = temp->next->next;
            delete temp->next;
            temp->next = t;
            return;
        }
        temp = temp->next;
    }
}

bool Chaining :: ch_search(string s_key, int key) {
    lookups = 0;
    int index = hash(key);

    Node* temp = table[index].head;
    while(temp != nullptr) {
        lookups++;
        if (temp->data.get_key() == s_key)
            return true;
        temp = temp->next;
    }
    return false;
}
