#include "./Barbarian.hpp"

Barbarian::Barbarian(string name) : Character(name,Job::BarbarianJob,200,0,15,900,100) {
    baseAttack = this->physicalAttack;
    baseDefense = this->defense;
    inFury = false;
}

void Barbarian::enterFury(){
    if( inFury ){
        throw IllegalFury(true);
    }
    baseAttack = this->physicalAttack;
    baseDefense = this->defense;
    inFury = true;
    physicalAttack *= 1.5f;
    defense = 0;
    this->receiveDamage(maxHp*0.15f);
}

void Barbarian::leaveFury(){
    if(!inFury){
        throw IllegalFury(false);
    }
    physicalAttack = baseAttack;
    defense = baseDefense;
    inFury = false;
}

string Barbarian::getSpecialActionName() {
    if(this->inFury) {
        return "Entrée en Furie";
    } else {
        return "Sortir de Furie";
    }
}

void Barbarian::launchSpecialAction(Character& target) {
    enterFury(target);
}