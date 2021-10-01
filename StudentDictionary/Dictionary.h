//
// Created by TaniaAggarwal on 5/25/2021.
//

#ifndef STUDENTDICTIONARY_DICTIONARY_H
#define STUDENTDICTIONARY_DICTIONARY_H

#include "Student.h"
#include "Chaining.h"
#include "LinearProbing.h"
#include "DoubleHashing.h"
#include "Universal_Hashing.h"

class Dictionary {
    int total_size;
    int total_lookups;
    int operations;
    Chaining* ch;
    LinearProbing* lp;
    DoubleHashing* dh;
    Universal_Hashing uh;
public:

    explicit Dictionary(int n);
    void insert(Student s, int hash_choice, int collision_choice);
    int insert_c(Student s, int hash_choice, int collision_choice);
    void remove(string s_key, int hash_choice, int collision_choice);
    int remove_c(string s_key, int hash_choice, int collision_choice);
    bool search(string s_key, int hash_choice, int collision_choice);
    int search_c(string s_key, int hash_choice, int collision_choice);

    float avg_lookups();
};


#endif //STUDENTDICTIONARY_DICTIONARY_H
