//
// Created by TaniaAggarwal on 5/24/2021.
//

#include "LinearProbing.h"
#include "Student.h"
#include "HashFunctions.h"

LinearProbing :: LinearProbing(int size) {
    int prime = nextPrime(size);
    array_size = prime;
    table = new Student[array_size];
    tombstone = 0;
}

int LinearProbing :: Hash(int key) {
    return (key % array_size);
}

void LinearProbing :: lp_insertion(Student s, int key) {
    lookups = 1;
    string s_key = s.get_key();
    int index = Hash(key);

    while (table[index].get_key() != "" && table[index].get_key() != "deleted" && table[index].get_key() != s_key) {
        lookups++;
        index = (index + 1) % array_size;
    }
    if (table[index].get_key() == s_key)
        return;
    else {
        if (table[index].get_key() == "deleted")
            tombstone--;
        table[index] = s;
    }
}

void LinearProbing :: lp_deletion(string s_key, int key) {
    lookups = 1;
    int index = Hash(key);
    int i=index;

    while(table[i].get_key() != "") {
        if (table[i].get_key() == s_key) {
            table[i].set_key("deleted");
            tombstone++;
            return;
        }
        lookups++;
        i = (i+1) % array_size;
        if (i==index)
            return;
    }
}

bool LinearProbing :: lp_search(string s_key, int key) {
    lookups = 1;
    int index = Hash(key);
    int i = index;
    while (table[i].get_key() != "") {
        if (table[i].get_key() == s_key)
            return true;
        lookups++;
        i = (i+1)%array_size;

        if (i==index)
            return false;
    }
    return false;
}