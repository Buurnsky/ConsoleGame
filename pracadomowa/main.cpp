#include <iostream>
#include <thread>         
#include <chrono> 
#include <cstdlib>
using namespace std;
class HeroClass
{
    public:
    int HP;
    int Attack;
    
};

// void which wirte line of stars 
void stars ()
{
cout<< "****************************************************"<<endl;
};

int WarriorAttack( HeroClass Warrior, HeroClass Monster )
{
    cout << "Warrior attack"<< endl;
    Monster.HP = Monster.HP-Warrior.Attack;
    cout << "Monster HP :" << Monster.HP<<endl;
    stars();
    return  Monster.HP;


}

int MonsterAttack( HeroClass Warrior, HeroClass Monster)
{
    cout << "Monster attack"<< endl;
    Warrior.HP = Warrior.HP -Monster.Attack;
    cout << "Warrior HP :" << Warrior.HP<< endl;
    stars();
    return Warrior.HP;
}

  bool checkIfEndGame ( HeroClass Warrior, HeroClass Monster , bool endGame)
{
    if(Warrior.HP == 0 or Warrior.HP < 0 )
        {
            endGame = true;
            cout << " Monster Win"<< endl;
            stars();
            return endGame; 
        }
        else if (Monster.HP == 0 or Monster.HP <0 )
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
    stars();
    HeroClass Warrior1;
    Warrior1.HP = (80 + (rand()%21));
    Warrior1.Attack = (5 + (rand()%10));
    //Warrior1.WarriorLuck = float(1 + float(rand()%3));
    HeroClass Monster1;
    Monster1.HP = (80 + (rand()%31));
    Monster1.Attack = (5+(rand()%15));
    cout<< "Warrior parameters: "<<endl;
    cout<< "HP : "<< Warrior1.HP << endl;
    cout<< "Atak : "<< Warrior1.Attack << endl;
    // cout<< "Luck : "<< Warrior1.WarriorLuck << endl;
    stars();
    cout<< "Monster parameters: "<<endl;
    cout<< "HP : "<< Monster1.HP<< endl;
    cout<< "Atak : "<< Monster1.Attack << endl;
    stars();
    int howStart;
    howStart = (1+ (rand()%101));
    cout<< " how start : "<< howStart <<endl;
    
    if(howStart>50)
    {
     cout << "Warrior start"<< endl;
     stars();
        while (endGame ==  false)
        {
        
            Monster1.HP = WarriorAttack(Warrior1,Monster1);
            this_thread::sleep_for (std::chrono::seconds(1));
            endGame = checkIfEndGame(Warrior1,Monster1 ,endGame);
        
            if ( endGame == true)
            {
                break;
            }
            else{
                Warrior1.HP = MonsterAttack(Warrior1,Monster1);
            }
                this_thread::sleep_for (std::chrono::seconds(1));
                endGame = checkIfEndGame(Warrior1,Monster1,endGame);    
        }
    }
    else
    {
        cout<<"Monster start"<<endl;
        stars();
    }
    
}