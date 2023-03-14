// Pattern_Fasad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>
using namespace std;

class Washing  // класс стирка
{
    int time;
public:
    Washing() : time(0) {}
    Washing(int timeP) : time(timeP) {}
    void Start()
    {
        cout << "Start process:" << endl;
    }
    void Wash()
    {
        cout << "Washing for " << time << " minutes" << endl;
    }
};

class Rinsing  // класс полоскание
{
    int time;
public:
    Rinsing() : time(0) {}
    Rinsing(int timeP) : time(timeP) {}
    void Rinse()
    {
        cout << "Rinsing for " << time << " minutes" << endl;
    }
};

class Spinning  // класс отжим
{
    int time;
public:
    Spinning() : time(0) {}
    Spinning(int timeP) : time(timeP) {}
    void Spinn()
    {
        cout << "Spinning for " << time << " minutes" << endl;
    }
    void Finish()
    {
        cout << "Process completed" << endl;
    }
};

class WMFacade  // класс Фасад
{
    Washing wash;  // стирка
    Rinsing rinse;  // полоскание 
    Spinning squeeze;  // отжим

public:
    WMFacade(Washing w, Rinsing r, Spinning s)
        : wash(w), rinse(r), squeeze(s) {}
  
    void Start()
    {
        wash.Start();
    }
    void Process()
    {
        wash.Wash();
        rinse.Rinse();
        squeeze.Spinn();
    }
    void Stop()
    {
        squeeze.Finish();
    }
};

class User  // класс пользователь
{
public:
    void UseWM(WMFacade facade)
    {
        facade.Start();
        facade.Process();
        facade.Stop();
    }
};

int main()
{
    
    Washing wash1(45);    // объект стирка                         
    Rinsing  rinse1(15);  // объект полоскание 
    Spinning spinn1(5);   // объект отжим

    WMFacade machine(wash1, rinse1, spinn1); // создаем фасад - машину
                                             // все процессы включены в фасад 

    User user;            // пользователь
    user.UseWM(machine);  
}