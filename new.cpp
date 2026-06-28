//
// Created by Admin on 28.06.2026.
//

#include <iostream>
#include <vector>
using namespace std;

class Player {
public:
    string name;
    int hp = 35;
    int attack = 10;
    int potions = 3;

    Player (string n, int h) {
        name = n;
        hp = h;
    }

    ~Player() {
        cout << name << " Player had been deleted" << endl;
    }
};
class Enemy {
public:
    string name;
    int hp;
    int attack;
    ~Enemy() {
        cout << name << " Enemy had been deleted" << endl;
    }

};

class Goblin : public Enemy {
public:
    Goblin() {
        name = "Goblin";
        hp = 30;
        attack = 8;
    }
};
class Troll : public Enemy {
public:
    Troll() {
        name = "Troll";
        hp = 80;
        attack = 20;

    }
};
class Dragon : public Enemy {
public:
    Dragon() {
        name = "Dragon";
        hp = 100;
        attack = 45;
    }
};


void fight(Player& p, Enemy& e) {
    cout << "Information about both players" << endl;

    cout << "Player " << p.name << endl;
    cout << "HP: " << p.hp << " | ATK: " << p.attack << endl;
}

int main() {
    Player* player = new Player("Hero", 100);

    vector<Enemy*> enemies = {new Goblin(), new Troll(), new Dragon()};

    for (Enemy* e : enemies) {
        if (player->hp <= 0) break;
        fight(*player, *e);
        while (player->hp > 0 && e->hp > 0) {
            e->hp -= player->attack;
            cout << player->name << " hits " << e->name << " for " << player->attack << " damage! Enemy HP: " << e->hp << endl;
            if (e->hp > 0) {
                player->hp -= e->attack;
                cout << e->name << " hits " << player->name << " for " << e->attack << " damage! Your HP: " << player->hp << endl;
            }
        }
    }

    if (player->hp > 0) cout << "Winner: " << player->name << endl;
    else cout << "Enemy wins!" << endl;

    for (Enemy* e : enemies) {
        delete e;
    }
    delete player;
    player = nullptr;

    return 0;
}