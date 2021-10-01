//
// Created by TaniaAggarwal on 5/24/2021.
//

#ifndef STUDENTDICTIONARY_LINEARPROBING_H
#define STUDENTDICTIONARY_LINEARPROBING_H

#include "Student.h"


class LinearProbing {
    int array_size;
    Student* table;
    int tombstone;

public:
    int lookups;

    LinearProbing(int size);
    int Hash(int key);
    void lp_insertion(Student s, int key);
    void lp_deletion(string s_key, int key);
    bool lp_search(string s_key, int key);
};


#endif //STUDENTDICTIONARY_LINEARPROBING_H
