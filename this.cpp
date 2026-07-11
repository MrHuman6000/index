#include <iostream>
#include <string>

using namespace std;

class Player {
public:
    string name;
    int hp;
    int attackp;
};

class Enemy {
public:
    string name;
    int hp;
    int attacke;
};

void Damage(int* hp, int attack) {
    if (hp == nullptr) {
        cout << "Error " << endl;
    }
    *hp = attack;
}


int main() {

    Player p;
    p.hp = 100;
    p.attackp = 0;

    Enemy e;
    e.hp = 100;
    e.attacke = 0;

    int decision;
    int decisions;
    string yesorno;
    cout << "Welcome to Damage game!";

    cout << "Set the name for a player: " << endl;
    cin >> p.name;
    cout << "Set the name for a enemy: " << endl;
    cin >> e.name;

    cout << "Set the damage for a player: "  << endl;
    cin >> p.attackp;
    cout << "Set the damage for a enemy: "<< endl;
    cin >> e.attacke;

    cout << "Start the match? (yes/no)" << endl;
    cin >> yesorno;

    if (yesorno == "yes") {
        cout << "Match start rn!" << endl;
        while (p.hp > 0 && e.hp > 0) {
            cout << "Enemy damaged the player! " << endl;
            p.hp -= e.attacke;
            cout << "Player has " << p.hp << " hp!" << endl;

            cout << "Player damaged the enemy! " << endl;
            e.hp -= p.attackp;
            cout << "Enemy has " << e.hp << " hp!" << endl;

            if (e.hp > 0 ) {
                cout << "Winner is Enemy!" << endl;
            }else if (p.hp > 0) {
                cout << "Winner is Player!" << endl;
            }

        }
    }else {
        cout << "Goodbye!" << endl;
    }
    return 0;
}