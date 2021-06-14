#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "./Potion.hpp"
#include <string>

using namespace std;

enum Job {
    FreelancerJob,
    MageJob,
    WarriorJob,
    BarbarianJob,
    DruidJob,
    PriestJob,
    PaladinJob,
};

class Character
{

    public:
    string name;

    protected:
    
    int physicalAttack;
    int magicAttack;
    int defense;
    int maxHp;
    int hp;
    int speed;

    private:
    Job job;

    public:
    Character() : Character("John Doe",FreelancerJob,100,100,50,1000,200){}

    Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp, int speed);

    void heal(unsigned int healingValue);

    void drink(Potion& p);

    Character& operator+=(Potion& p);

    void attack(Character& defender);

    int getCurrentHp();

    public:
    void receiveDamage(int damage);
    void getSpecialActionName();
    void launchSpecialAction(Character& target);  
};

#endif