//
// Created by TaniaAggarwal on 5/24/2021.
//

#include "DoubleHashing.h"
#include "HashFunctions.h"
#include "Student.h"

DoubleHashing::DoubleHashing(int size) {
    int prime = nextPrime(size);
    array_size = prime;
    table = new Student[array_size];
}

int DoubleHashing::hash1(int key) {
    return (key % array_size);
}

int DoubleHashing::hash2(int key) {
    return array_size - (key % array_size);
}

void DoubleHashing :: dh_insertion(Student s, int key) {
    lookups = 1;
    string s_key = s.get_key();

    int probe = hash1(key);
    int offset = hash2(key);

    int i=1;
    while (table[probe].get_key() != "" && table[probe].get_key() != "deleted" && table[probe].get_key() != s_key) {
        lookups++;
        probe = (probe + i * offset) % array_size;
        i++;
    }
    if (table[probe].get_key() == s_key)
        return;
    else {
        table[probe] = s;
    }
}

void DoubleHashing :: dh_deletion(string s_key, int key) {
    lookups = 1;
    int probe = hash1(key);
    int offset = hash2(key);
    int i=probe;

    int j=1;
    while(table[i].get_key() != "") {
        if (table[i].get_key() == s_key) {
            table[i].set_key("deleted");
            return;
        }
        lookups++;
        i = (i + j * offset) % array_size;
        if (i==probe)
            return;
    }
}

bool DoubleHashing :: dh_search(string s_key, int key) {
    lookups = 1;
    int probe = hash1(key);
    int offset = hash2(key);

    int i = probe;
    int j = 1;
    while (table[i].get_key() != "") {
        if (table[i].get_key() == s_key)
            return true;
        lookups++;
        i = (i + j * offset) % array_size;

        if (i == probe)
            return false;
    }
    return false;
}




