//
// Created by TaniaAggarwal on 5/25/2021.
//

#include "Universal_Hashing.h"
#include "HashFunctions.h"
#include <math.h>

Universal_Hashing :: Universal_Hashing() {
    num = rand()%2;
}

int Universal_Hashing::hashing(string s_key) {
    int key;
    if (num==0) {
        key = component_sum(s_key);
    } else {
        key = polynomial_accumulation(s_key);
    }
    return key;
}
