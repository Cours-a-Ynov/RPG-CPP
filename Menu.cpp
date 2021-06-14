    #include <cstdlib>
    #include <iostream>
    #include "./Character.cpp"
    #include "./Menu.hpp"

    using namespace std;
    


Character selection() {
    
   for (int i = 0 ; i< sizeof(cibleList);i++) {
       cout << i << " : " << cibleList[i].name << endl;
    }
   
    cin >> cible;
    if (cible != 0) {
        if (cible < sizeof(cibleList)) {
            return cibleList[cible];
        }
    }
}


int interface(Character perso) {
    
    cout << perso.name << endl;
    cout << "pv restant : " << perso.hp << "/" << perso.maxHp << endl;
    cout << perso.job << endl;

    cout << "Veillez sélectioné votre action !" << endl;
    cout << "1 : Attaqué" << endl;
    cout << "2 : Action de Classe" << endl;
    cout << "3 : boire une potion" << endl;

    cin >> actionSelected ;

    if (actionSelected == 1) {
        cibleSelected = selection();
        perso.attack(cibleSelected);


    } else if (actionSelected == 2) {
        cibleSelected = selection();
        perso.launchSpecialAction(cibleSelected);

    } else if (actionSelected == 3) {
        perso.drink(PotionSelected);
    } else {
        cout << "vous avez rentré une information invalide" << endl;
    }
}