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

    HeroClass(int HPPar, int AttackPra)
    {
        HP = HPPar;
        Attack = AttackPra;
    }
};

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

void game(HeroClass Warrior1, HeroClass Monster1, int howStart)
{
    bool endGame = false; 
    cout<< " how start : "<< howStart <<endl;
    if(howStart>50)
    {
     cout << "Warrior start"<< endl;
     stars();
     this_thread::sleep_for (std::chrono::seconds(5));
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
        this_thread::sleep_for (std::chrono::seconds(5));
         while (endGame ==  false)
        {
            Warrior1.HP = MonsterAttack(Warrior1,Monster1);
            
            this_thread::sleep_for (std::chrono::seconds(1));
            endGame = checkIfEndGame(Warrior1,Monster1 ,endGame);
        
            if ( endGame == true)
            {
                break;
            }
            else{
                Monster1.HP = WarriorAttack(Warrior1,Monster1);
            }
                this_thread::sleep_for (std::chrono::seconds(1));
                endGame = checkIfEndGame(Warrior1,Monster1,endGame);    
        }
    }
}

int main()
{
    srand((unsigned) time(NULL));
    
// tworzenie  broni  zbroji itp.


// tworzenie postaci
    //ile postaci ma być stworzone

    // tworzenie postać wojownik 
    stars();
    cout<< "Herros Paramters :"<< endl;
    HeroClass Warrior((80 + (rand()%21)),(5 + (rand()%10)));
    cout<< "Warrior HP : "<< Warrior.HP<<" Attack : "<< Warrior.Attack<<endl;
    
    // towrzenie  postać potwór
    HeroClass Monster((80 + (rand()%31)),(5+(rand()%15)));
    cout<< "Monster HP : "<< Monster.HP<<" Attack : "<< Monster.Attack<<endl;
    stars();
    
    // przenisienie do walki  (start walki ) 
    int howStart;
    howStart = (1+ (rand()%101));    
    game(Warrior,Monster,howStart);
    // zapytanie ile czy rozpacząc jeszcze raz gre  

}
