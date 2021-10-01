//
// Created by TaniaAggarwal on 5/24/2021.
//

#ifndef STUDENTDICTIONARY_DOUBLEHASHING_H
#define STUDENTDICTIONARY_DOUBLEHASHING_H

#include "Student.h"

class DoubleHashing {
    int array_size;
    Student* table;

public:
    int lookups;

    DoubleHashing(int size);
    int hash1(int key);
    int hash2(int key);
    void dh_insertion(Student s, int key);
    void dh_deletion(string s_key, int key);
    bool dh_search(string s_key, int key);
};


#endif //STUDENTDICTIONARY_DOUBLEHASHING_H
