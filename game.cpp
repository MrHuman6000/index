//
// Created by Admin on 28.06.2026.
//

#include <iostream>
#include <vector>

using namespace std;

class Player {
public:
    string name;
    int hp = 150;
    int attack = 20;

    Player(string n, int h) {
        name = n;
        hp = h;
    }

    ~Player() {
        cout << "The player had been deleted from memory" << endl;
    }
};
class Enemy {
    public:
    string name;
    int hp;
    int attack;

    ~Enemy() {
        cout << "The enemy had been deleted from memory" << endl;
    }

};

class Dragon : public Enemy {
public:
    Dragon() {
        name = "Dragon";
        hp = 100;
        attack = 25;
    }
};
class Skelet : public Enemy {
public:
    Skelet() {
        name = "Skelet";
        hp = 25;
        attack = 25;
    }
};
class Zombie : public Enemy {
public:
    Zombie() {
        name = "Zombie";
        hp = 25;
        attack = 25;
    }
};


void Regeneration(int* quantity_potions, int reg) {
    if (quantity_potions == nullptr) {
        cout << "Error!" << endl;
    }
    *quantity_potions += reg;

}

void fight(Player& p, Enemy& e) {
    cout << "Information about both players" << endl;

    cout << "Player " << p.name << endl;
    cout << "HP: " << p.hp << " | ATK: " << p.attack << endl;
}

int main() {

    int quantity_potions = 3;
    string e_name= "";

    Player* player = new Player("Steve", 100);
    vector<Enemy*> enemies = {new Dragon(), new Skelet(), new Zombie()};

    for (Enemy* e : enemies) {
        e_name = e->name;
        if (player->hp <= 0) break;
        fight(*player, *e);
        while (player->hp > 0 && e->hp > 0) {
            e->hp -= player->attack;
            cout << player->name << " hits " << e->name << " for " << player->attack << " damage! Enemy HP: " << e->hp << endl;
            if (e->hp > 0) {
                player->hp -= e->attack;
                cout << e->name << " hits " << player->name << " for " << e->attack << " damage! Your HP: " << player->hp << endl;
            }
            if (player->hp < 20 && quantity_potions > 0) {
                Regeneration(&player->hp, 30);
                cout << "Your HP: " << player->hp << endl;
                quantity_potions--;
            }
        }
    }
    if (player->hp > 0) {
        cout << "Winner: " << player->name << endl;
    }else {
        cout << "Winner: " << e_name << endl;
    }
    for (Enemy* e : enemies) {
        delete e;
        e = nullptr;
    }

    delete player;
    player = nullptr;

    return 0;
}