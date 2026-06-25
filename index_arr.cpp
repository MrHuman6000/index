//
// Created by Admin on 25.06.2026.
//

#include <iostream>

using namespace std;

int main() {
    int enemies[3] = {50, 80, 120};
    int* p = enemies;

    cout << *p << endl;
    cout << *(p+1) << endl;
    cout << *(p+2) << endl;
}