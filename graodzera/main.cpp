#include <iostream>
#include <thread>         
#include <chrono> 
#include <cstdlib>

using namespace std;
 
 void stars ()
{
cout<< "****************************************************"<<endl;
};

class HeroClass 
{
    public:
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
        void game( int howStart)
        {
            
            Warrior.setParameters((80 + (rand()%21)),(5 + (rand()%10)),2);
            cout<< "Warrior HP : "<< Warrior.HP<<" Attack : "<< Warrior.Attack<<endl;
            stars();
            Monster.setParameters((80 + (rand()%31)),(5+(rand()%15)),1);
            cout<< "Monster HP : "<< Monster.HP<<" Attack : "<< Monster.Attack<<endl;
            stars();

            bool endGame = false; 
            cout<< " how start : "<< howStart <<endl;
            if(howStart>50)
            {
                cout << "Warrior start"<< endl;
                stars();
                this_thread::sleep_for (std::chrono::seconds(5));
                while (endGame ==  false)
                {       
                Monster.HP = HPAfterAttack(Monster,Warrior);
                // Monster1.HP = WarriorAttack(Warrior1,Monster1);
                cout<< "Monster HP :"<<Monster.HP << " after Warrior attack"<< endl;
                stars();
                this_thread::sleep_for (std::chrono::seconds(1));
                endGame = checkIfEndGame(Warrior,Monster ,endGame);
        
                if ( endGame == true)
                    {
                    break;
                    }
                else{
                    Warrior.HP= HPAfterAttack(Warrior,Monster);
                    cout<< "Warrior HP :"<<Warrior.HP << " after Monster attack"<< endl;
                    stars();
                    // Warrior1.HP = MonsterAttack(Warrior1,Monster1);
                }
                    this_thread::sleep_for (std::chrono::seconds(1));
                    endGame = checkIfEndGame(Warrior,Monster,endGame);    
                }
             }  
             else
             {
                 cout<<"Monster start"<<endl;
                stars();
                 this_thread::sleep_for (std::chrono::seconds(5));
                while (endGame ==  false)
             {
                Warrior.HP= HPAfterAttack(Warrior,Monster);
                cout<< "Warrior HP :"<<Warrior.HP << " after Monster attack"<< endl;
                stars(); 
                // Warrior1.HP = MonsterAttack(Warrior1,Monster1);
            
                this_thread::sleep_for (std::chrono::seconds(1));
                endGame = checkIfEndGame(Warrior,Monster ,endGame);
        
                 if ( endGame == true)
                {
                     break;
                 }
                else
                {

                    Monster.HP =HPAfterAttack(Monster,Warrior);
                    cout<< "Monster HP :"<<Monster.HP << " after Warrior attack"<< endl;
                    stars();
                    // Monster1.HP = WarriorAttack(Warrior1,Monster1);
                }
                    this_thread::sleep_for (std::chrono::seconds(1));
                    endGame = checkIfEndGame(Warrior,Monster,endGame);    
            }
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
