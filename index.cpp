//
// Created by Admin on 25.06.2026.
//

#include <iostream>

using namespace std;

void heal(int *hp, int amount) {
    *hp += amount;
}
int main() {

    int hp = 60;
    heal(&hp, 25);

    cout << hp << endl;
}