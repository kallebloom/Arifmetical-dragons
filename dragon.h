#ifndef DRAGON_H_INCLUDED
#define DRAGON_H_INCLUDED

#include <string>
#include <sstream>
#include <math.h>
class Dragon: public Unit
{
protected:
    int my_answer;
    std::string my_color;
public:
    static const int c_killScores = 100;

    Dragon(std::string color, int start_health, int _attackForce)
        :Unit(start_health, _attackForce), my_color(color)
    {}

    virtual std::string generateQuestion() = 0;

    bool checkAnswer(int answer) const
    {
        return answer == my_answer;
    }
    std::string color() const
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
    std::string generateQuestion()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

       std::stringstream question;
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
    std::string generateQuestion()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        std::stringstream question;
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
    std::string generateQuestion()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        std::stringstream question;
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
#endif // DRAGON_H_INCLUDED
