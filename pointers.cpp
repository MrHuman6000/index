#include <iostream>

using namespace std;


void Deaths(int* deaths, int quantity) {
    if (deaths == nullptr) {
        cout << "Error" << endl;
    }else {
        *deaths += quantity;
    }
}

int main() {
    int total = 0;
    Deaths(&total, 5);
    cout << total << endl;
}