#include "Wizard.h"

Wizard::Wizard(string cname, double initialHealth, double strength, int r) : Character(WIZARD, cname, initialHealth, strength) {
    rank = r;
}

void Wizard::attack(Character& opponent) {
    double damage = 0.0;
    
    if(!opponent.isAlive()) {
        return;
    }
    if(opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        damage = this->attackStrength * (static_cast<double>(this->rank) / opp.getRank());
    }
    else {
        damage = this->attackStrength;
    }
    
    if(opponent.getHealth() > damage) {
        opponent.setHealth(opponent.getHealth() - damage);
    }
    else {
        opponent.setHealth(0);
    }
    
    cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    if(opponent.isAlive()) {
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else {
        cout << opponent.getName() << " is dead!" << endl;
    }
    
    return;
}

int Wizard::getRank() const {
    return rank;
}