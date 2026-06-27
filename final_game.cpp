#include <iostream>
#include <string>

using namespace std;
void Message(int* messages) {
    if (messages == nullptr) {
        cout << "Error" << endl;
        return;
    }
    *messages += 1;
}
int main() {
    string answer;
    int messageCount = 0;
    int* m = &messageCount;

    cout << "You have " << *m << "messages" << endl;
    cout << "Do you want to recieve 1 message? Y/N" << endl;
    cin >> answer;

    if (answer == "Y" || answer == "y") {
        Message(m);
        cout << "Message received! Now you have: " << *m << " messages." << endl;
    } else {
        cout << "Good bye!" << endl;
    }
}