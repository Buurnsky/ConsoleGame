#include <iostream>
#include <thread>         
#include <chrono> 
#include <cstdlib>

using namespace std;
 
 void stars ()
{
cout<< "****************************************************"<<endl;
};

class WeaponClass
{
    public :
    int WeaponPower;
};

class HeroClass 
{
    public:
    string name;
    int HP;
    int Attack;
    int Weapon;

    void setParameters(int HPPar, int AttackPra, int WeaponPar)
    {
        HP = HPPar;
        Attack = AttackPra;
        Weapon = WeaponPar;
    }

    
};
class GameClass   
{
    public:

        HeroClass Monster;        
        HeroClass Warrior;
        WeaponClass WarriorWeapon;
        WeaponClass MonsterWeapon;

        int HPAfterAttack( HeroClass Hero1, HeroClass Hero2)
        {
            Hero1.HP = Hero1.HP-(Hero2.Attack+Hero2.Weapon);
            return(Hero1.HP);
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
        
        void attack(HeroClass Hero1, HeroClass Hero2, bool endGame)
        {
            cout<< Hero1.name << " start"<< endl;
                stars();
                this_thread::sleep_for (std::chrono::seconds(5));
                while (endGame ==  false)
                {       
                Hero2.HP = HPAfterAttack(Hero2,Hero1);
                // Monster1.HP = WarriorAttack(Warrior1,Monster1);
                cout<< Hero2.name <<" HP :"<<Hero2.HP << " after " <<Hero1.name<< " attack"<< endl;
                stars();
                this_thread::sleep_for (std::chrono::seconds(1));
                endGame = checkIfEndGame(Hero1,Hero2 ,endGame);
        
                if ( endGame == true)
                    {
                    break;
                    }
                else{
                    Hero1.HP= HPAfterAttack(Hero1,Hero2);
                    cout<< Hero1.name <<" HP : "<<Hero1.HP << " after "<< Hero2.name<<" attack"<< endl;
                    stars();
                    // Warrior1.HP = MonsterAttack(Warrior1,Monster1);
                }
                    this_thread::sleep_for (std::chrono::seconds(1));
                    endGame = checkIfEndGame(Hero1,Hero2,endGame);    
                }
        }
        void game( int howStart)
        {
            WarriorWeapon.WeaponPower = (2+rand()%10);
            MonsterWeapon.WeaponPower = (1+rand()%7);
            Warrior.name = "Warrior";
            Monster.name = "Monster";
            Warrior.setParameters((80 + (rand()%21)),(5 + (rand()%10)),WarriorWeapon.WeaponPower);
            cout<< "Warrior HP : "<< Warrior.HP<<" Attack : "<< Warrior.Attack<<" Weapon Power : "<<Warrior.Weapon<< endl;
            stars();
            Monster.setParameters((80 + (rand()%31)),(5+(rand()%15)),MonsterWeapon.WeaponPower);
            cout<< "Monster HP : "<< Monster.HP<<" Attack : "<< Monster.Attack<<" Weapon Power : "<<Monster.Weapon<< endl;
            stars();

            bool endGame = false; 
            cout<< " how start : "<< howStart <<endl;
            if(howStart>50)
            {   
                attack(Warrior,Monster,endGame);
             }  
             else
             {
                attack(Monster,Warrior,endGame);
            }
        }     
            
    
};


int main()
{
    srand((unsigned) time(NULL));
    GameClass game;
    GameClass game2 ;

    // tworzenie postać wojownik 
    stars();
    // przenisienie do walki  (start walki ) 
    int howStart;
    howStart = (1+ (rand()%101));    
    game.game(howStart);
    howStart = (1+ (rand()%101));    
    game2.game(howStart);

    // game(Warrior,Monster,howStart);
    // zapytanie ile czy rozpacząc jeszcze raz gre  

}
