//
// Created by Admin on 25.06.2026.
//
#include <iostream>

using namespace std;

int main() {
    int* p = nullptr;

    if (p == nullptr) cout << "hp not found" << endl;

    int hp = 100;
    p = &hp;

    if (p != nullptr) cout << *p << endl;
}