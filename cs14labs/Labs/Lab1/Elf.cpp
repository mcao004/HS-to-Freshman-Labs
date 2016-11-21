#include "Elf.h"

Elf::Elf(string cname, double initialHealth, double strength, string fam) : Character(ELF, cname, initialHealth, strength) {
    family = fam;
}

void Elf::attack(Character& opponent) {
    double damage = 0.0;
    
    if(!opponent.isAlive()) {
        return;
    }
    if(opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(this->family == opp.getFamily()) {
            cout << "Elf " << this->name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << this->family << " family." << endl;
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
    
        cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    if(opponent.isAlive()) { 
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else {
        cout << opponent.getName() << " is dead!" << endl;
    }
    
    return;
}

string Elf::getFamily() const {
    return family;
}