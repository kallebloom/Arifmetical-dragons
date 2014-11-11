#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>
#include <math.h>

using namespace std;
int a;
class Unit
{
protected:
    int health;
public:
    int attackForce;

    Unit(int start_health, int _attackForce)
        :health(start_health), attackForce(_attackForce)
    {}
    void getDamage(int damage)
    {
        health -= damage;
    }
    int getHealth() const
    {
        return health;
    }
    bool isAlive() const
    {
        return (health > 0);
    }
};

class Dragon: public Unit
{
protected:
    int my_answer;
    string my_color;
public:
    static const int c_killScores = 100;

    Dragon(string color, int start_health, int _attackForce)
        :Unit(start_health, _attackForce), my_color(color)
   {}

    virtual string generateQuestion() = 0;

    bool checkAnswer(int answer) const
    {
        return answer == my_answer;
    }
    string color() const
    {
        return my_color;
    }
};

class GreenDragon: public Dragon
{
    static const int c_greenDragonHealth = 50;
    static const int c_greenDragonAttackForce = 5;
public:

    GreenDragon()
        :Dragon("Green", c_greenDragonHealth, c_greenDragonAttackForce)
    {}
    string generateQuestion()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        stringstream question;
       question << left << " + " << right << ": ";
        my_answer = left + right;
        return question.str();
    }
};

class RedDragon: public Dragon
{
    static const int c_redDragonHealth = 30;
    static const int c_redDragonAttackForce = 10;
public:

    RedDragon()
        :Dragon("Red", c_redDragonHealth, c_redDragonAttackForce)
    {}
    string generateQuestion()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        stringstream question;
        question << left << " - " << right << ": ";
        my_answer = left - right;
        return question.str();
    }
};

class BlackDragon: public Dragon
{
    static const int c_blackDragonHealth = 20;
    static const int c_blackDragonAttackForce = 15;
public:

    BlackDragon()
        :Dragon("Black", c_blackDragonHealth, c_blackDragonAttackForce)
    {}
    string generateQuestion()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        stringstream question;
        question << left << " * " << right << ": ";
        my_answer = left * right;
        return question.str();
    }
};

class Troll: public Dragon
{   static const int c_TrollHealth = 20;
    static const int c_TrollAttackForce = 15;
    bool prime();

public:
    int left = 1 + rand()%100;


       Troll()
        :Dragon("Troll", c_TrollHealth, c_TrollAttackForce)
    {}

                    bool prime(long long left)
                    {
                    for(long long i=2;i<=sqrt(left);i++)
                        if(left%i==0)
                        char a = 'No';
                    char a = 'Yes';
                    }
    string generateQuestion()
       {

        stringstream question;
        question << left << " Prime number? " <<  ": ";
        my_answer = a;
        return question.str();
    }
};
class Hero: public Unit
{
    int scores;
public:
    static const int default_health = 100;
    static const int default_attackForce = 20;

    Hero(int health = default_health, int aForce = default_attackForce)
        :Unit(health, aForce), scores(0)
    {}
    void attack (Dragon &drago)
    {
        string q = drago.generateQuestion();
        cout << "question: " << q;
        int answer;
        cin >> answer;
        if (drago.checkAnswer(answer))
        {
            drago.getDamage(attackForce);
            cout << "Hit you, enemy!" << endl;
        }
        else
        {
            getDamage(drago.attackForce);
            cout << "Hero suffers..." << endl;
        }
    }
    void addScores(int _scores)
    {
        scores += _scores;
    }
    int getScores()
    {
        return scores;
    }
};

void showHealth(const Hero &hero, const Dragon &dragon)
{
    cout << "Hero health: " << hero.getHealth()
        << ", Enemy health: " << dragon.getHealth() << endl;
}

list<Dragon*> generateDragonList()
{
    list<Dragon*> competitors;
    competitors.push_back(new GreenDragon());
    competitors.push_back(new RedDragon());
    competitors.push_back(new BlackDragon());
    competitors.push_back(new Troll());
    return competitors;
}


bool playGame(Hero &hero, list<Dragon*> &dragons)
{
    bool gameOver = false;

    for (list<Dragon*>::iterator dragon = dragons.begin();
            dragon != dragons.end(); dragon++)
    {
        cout << "You have met a new " << (*dragon)->color() << " dragon. Fight!" << endl;

        while ((*dragon)->isAlive() && hero.isAlive())
        {
            hero.attack(**dragon);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // dragon was killed!
        {
            hero.addScores(Dragon::c_killScores);
            cout << "Ough! You have killed an enemy!" << endl;
        }
    }
    return gameOver;
}


int main()
{
    Hero hero;
    list<Dragon*> dragons = generateDragonList();
    bool gameResult = playGame(hero, dragons);

    if (gameResult)
    {
        cout << "Game over! Your score is: " << hero.getScores() << endl;
    }
    else
    {
        cout << "You win! Your score is: " << hero.getScores() << endl;
    }
    for (list<Dragon*>::iterator dragon = dragons.begin();
            dragon != dragons.end(); dragon++)
        delete *dragon;
    return 0;
}
