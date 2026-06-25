//
// Created by Admin on 25.06.2026.
//

#include <iostream>

using namespace std;

void plushp(int *plus, int plushp) {
    if (plus == nullptr) {
        cout << "error: No target" << endl;
        return;
    }
    *plus += plushp;
}

int main() {

    plushp(nullptr, 30);
    int enemies[3] = {1, 2, 3};
    int* p = enemies;
    plushp(p,10);
    plushp(p+1,20);
    plushp(p+2,30);
    cout << *p << endl;
    cout << *(p+1) << endl;
    cout << *(p+2) << endl;


}