//
// Created by TaniaAggarwal on 5/25/2021.
//

#include "Dictionary.h"
#include "HashFunctions.h"
#include "Chaining.h"
#include "LinearProbing.h"
#include "DoubleHashing.h"
#include "Universal_Hashing.h"
#include <iostream>

Dictionary::Dictionary(int n) {
    total_lookups = operations = 0;
    total_size = n;
    ch = new Chaining(total_size);
    lp = new LinearProbing(total_size);
    dh = new DoubleHashing(total_size);
}

void Dictionary :: insert(Student s, int hash_choice, int collision_choice) {
    string s_key = s.get_key();

    /*find key*/
    int key;

    //component sum
    if (hash_choice == 1)
        key = component_sum(s_key);
    //polynomial accumulation
    else if (hash_choice == 2)
        key = polynomial_accumulation(s_key);
    //Universal hashing
    else if (hash_choice == 3)
        key = uh.hashing(s_key);

    /*collision resolution*/

    //Chaining
    if (collision_choice == 1) {
        ch->ch_insert(s, key);
    }
    //Linear Probing
    else if (collision_choice == 2) {
        lp->lp_insertion(s, key);
    }
    //Double hashing
    else {
        dh->dh_insertion(s, key);
    }
}

int Dictionary::insert_c(Student s, int hash_choice, int collision_choice) {
    operations++;
    insert(s, hash_choice, collision_choice);

    if (collision_choice == 1) {
        total_lookups += ch->lookups;
        return ch->lookups;
    }
        //Linear Probing
    else if (collision_choice == 2) {
        total_lookups = lp->lookups;
        return lp->lookups;
    }
        //Double hashing
    else {
        total_lookups += dh->lookups;
        return dh->lookups;
    }
}

void Dictionary::remove(string s_key, int hash_choice, int collision_choice) {

    /*find key*/
    int key;

    //component sum
    if (hash_choice == 1)
        key = component_sum(s_key);
        //polynomial accumulation
    else if (hash_choice == 2)
        key = polynomial_accumulation(s_key);
        //Universal hashing
    else if (hash_choice == 3)
        key = uh.hashing(s_key);

    /*collision resolution*/

    //Chaining
    if (collision_choice == 1) {
        ch->ch_remove(s_key, key);
    }
        //Linear Probing
    else if (collision_choice == 2) {
        lp->lp_deletion(s_key, key);
    }
        //Double hashing
    else {
        dh->dh_deletion(s_key, key);
    }
}

int Dictionary::remove_c(string s_key, int hash_choice, int collision_choice) {
    operations++;
    remove(s_key, hash_choice, collision_choice);

    if (collision_choice == 1) {
        total_lookups += ch->lookups;
        return ch->lookups;
    }
        //Linear Probing
    else if (collision_choice == 2) {
        total_lookups = lp->lookups;
        return lp->lookups;
    }
        //Double hashing
    else {
        total_lookups += dh->lookups;
        return dh->lookups;
    }
}

bool Dictionary::search(string s_key, int hash_choice, int collision_choice) {
    /*find key*/
    int key;

    //component sum
    if (hash_choice == 1)
        key = component_sum(s_key);
        //polynomial accumulation
    else if (hash_choice == 2)
        key = polynomial_accumulation(s_key);
        //Universal hashing
    else if (hash_choice == 3)
        key = uh.hashing(s_key);

    /*collision resolution*/

    //Chaining
    if (collision_choice == 1) {
        ch->ch_search(s_key, key);
    }
        //Linear Probing
    else if (collision_choice == 2) {
        lp->lp_search(s_key, key);
    }
        //Double hashing
    else {
        dh->dh_search(s_key, key);
    }
    return false;
}

int Dictionary::search_c(string s_key, int hash_choice, int collision_choice) {
    operations++;
    search(s_key, hash_choice, collision_choice);

    if (collision_choice == 1) {
        total_lookups += ch->lookups;
        return ch->lookups;
    }
        //Linear Probing
    else if (collision_choice == 2) {
        total_lookups = lp->lookups;
        return lp->lookups;
    }
        //Double hashing
    else {
        total_lookups += dh->lookups;
        return dh->lookups;
    }
}

float Dictionary::avg_lookups() {
    return ((float)total_lookups/(float)operations);
}




