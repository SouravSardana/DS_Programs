//
// Created by TaniaAggarwal on 5/24/2021.
//

#ifndef STUDENTDICTIONARY_CHAINING_H
#define STUDENTDICTIONARY_CHAINING_H

#include "LinkedList.h"
#include "Student.h"


class Chaining {
    int array_size;
    LinkedList *table;

public:
    int lookups;

    Chaining(int n);
    int hash(int key);
    void ch_insert(Student s, int key);
    void ch_remove(string s_key, int key);
    bool ch_search(string s_key, int key);
};


#endif //STUDENTDICTIONARY_CHAINING_H
