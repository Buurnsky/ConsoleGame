#include <iostream>
#include <thread>         
#include <chrono> 
#include <cstdlib>
using namespace std;
// Warrior class
class WarriorClass{
    public:
    int WarriorHP;
    int WarriorAttack;
    float WarriorLuck;

};

//Monster class
class MonsterClass{
    public:
    int monsterHP;
    int monsterAttack;
};

// void which wirte line of stars 
void stars ()
{
cout<< "****************************************************"<<endl;
};

int WarriorAttack( WarriorClass Warrior, MonsterClass Monster )
{
    cout << "Warrior attack"<< endl;
    Monster.monsterHP = Monster.monsterHP-Warrior.WarriorAttack;
    cout << "Monster HP :" << Monster.monsterHP<<endl;
    stars();
    return  Monster.monsterHP;


}

int MonsterAttack( WarriorClass Warrior, MonsterClass Monster)
{
    cout << "Monster attack"<< endl;
    Warrior.WarriorHP = Warrior.WarriorHP -Monster.monsterAttack;
    cout << "Warrior HP :" << Warrior.WarriorHP<< endl;
    stars();
    return Warrior.WarriorHP;
}

  bool checkIfEndGame ( WarriorClass Warrior, MonsterClass Monster , bool endGame)
{
    if(Warrior.WarriorHP == 0 or Warrior.WarriorHP < 0 )
        {
            endGame = true;
            cout << " Monster Win"<< endl;
            stars();
            return endGame; 
        }
        else if (Monster.monsterHP == 0 or Monster.monsterHP <0 )
        {
            endGame = true;
            cout << "Warrior Win"<< endl;
            stars();
           return endGame;
        }
        else
        {
            return endGame =  false; 
        }
}

int main()
{
    srand((unsigned) time(NULL)); 
    bool endGame = false;

    cout<< "The game will be here in some time \n\n" ;
    // int random = 1 + (rand() % 101);
    // cout << " rand value =";
    // cout<< random <<endl;
    stars();
    WarriorClass Warrior1;
    Warrior1.WarriorHP = (80 + (rand()%21));
    Warrior1.WarriorAttack = (5 + (rand()%10));
    Warrior1.WarriorLuck = float(1 + float(rand()%3));
    MonsterClass Monster1;
    Monster1.monsterHP = (80 + (rand()%31));
    Monster1.monsterAttack = (5+(rand()%15));
    cout<< "Warrior parameters: "<<endl;
    cout<< "HP : "<< Warrior1.WarriorHP << endl;
    cout<< "Atak : "<< Warrior1.WarriorAttack << endl;
    // cout<< "Luck : "<< Warrior1.WarriorLuck << endl;
    stars();
    cout<< "Monster parameters: "<<endl;
    cout<< "HP : "<< Monster1.monsterHP<< endl;
    cout<< "Atak : "<< Monster1.monsterAttack << endl;
    stars();
    
    // Monster1.monsterHP = WarriorAttack(Warrior1,Monster1);
    // cout<< Monster1.monsterHP<<endl;
    // stars();
    while (endGame ==  false)
    {
        /* code */
        Monster1.monsterHP = WarriorAttack(Warrior1,Monster1);
        this_thread::sleep_for (std::chrono::seconds(1));
        endGame = checkIfEndGame(Warrior1,Monster1 ,endGame);
        Warrior1.WarriorHP = MonsterAttack(Warrior1,Monster1);
        this_thread::sleep_for (std::chrono::seconds(1));
        endGame = checkIfEndGame(Warrior1,Monster1,endGame);
        
        
    }
    
    
}