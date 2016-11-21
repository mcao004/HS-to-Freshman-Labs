#include "Warrior.h"

Warrior::Warrior(string cname, double initialHealth, double strength, string alleg) : Character(WARRIOR, cname, initialHealth, strength) {
    allegiance = alleg;
}

void Warrior::attack(Character& opponent) {
    double damage = 0.0;
    
    if(!opponent.isAlive()) {
        return;
    }
    if(opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(this->allegiance == opp.getAllegiance()) {
            cout << "Warrior " << this->name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    }
    damage = (this->health / MAX_HEALTH) * this->attackStrength;
    if(opponent.getHealth() > damage) {
        opponent.setHealth(opponent.getHealth() - damage);
    }
    else {
        opponent.setHealth(0);
    }
    
    cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
    if(opponent.isAlive()) {
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else {
        cout << opponent.getName() << " is dead!" << endl;
    }
    
    return;
}

string Warrior::getAllegiance() const {
    return allegiance;
}