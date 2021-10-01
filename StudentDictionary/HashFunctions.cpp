//
// Created by TaniaAggarwal on 5/24/2021.
//
#include <string>
#include <math.h>
using namespace std;

int component_sum(string key) {
    int sum = 0;
    for (auto x: key) {
        sum += x;
    }
    return sum;
}

int polynomial_accumulation(string key) {
    int x = 33;
    long sum = 0;
    for (int i=0; i<key.length(); i++) {
        sum += (int(key[i]) * pow(x, i));
    }
    return sum;
}



bool isPrime(int n){

    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}

int nextPrime(int N) {

    if (N <= 1)
        return 2;

    int prime = N;
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}