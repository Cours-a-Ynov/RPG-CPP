#include "./Mage.hpp"

bool Mage::tryUsingMp(int mp){
    if(this->mp < mp){
        return false;
    }
    this->mp -= mp;
    return true;
}

void Mage::fireball(Character& other){
    if(!tryUsingMp(this->maxMp*0.10f)){
        return;
    }
    int randomNumber = rand() % 10;
    if(randomNumber == 0){
        return;
    }
    other.receiveDamage(this->magicAttack);
}

string Mage::getSpecialActionName() {
    if(tryUsingMp(0)) {
        return "Tirer votre boule de feu sur un ennemi";
    } else {
        return "Boule de feu (plus assez de point magique...)";
    }
}

void Mage::launchSpecialAction(Character& target) {
    fireball(target);
}