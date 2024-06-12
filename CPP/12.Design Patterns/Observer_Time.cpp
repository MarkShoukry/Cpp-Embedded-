#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observer
{
public:
    virtual void Update() = 0 ;
    virtual ~Observer() = default ;
};

class Observable
{
private:
    vector<Observer*> observers;
public:
    virtual void Attach(Observer& o)
    {
        observers.push_back(&o);
    }
    virtual void Detach(Observer &o)
    {
        observers.erase(remove(observers.begin(),observers.end(), &o));
    }

    void Notify()
    {
        for(auto *o : observers)
        {
            o->Update();
        }
    }
};


class Timer : public Observable
{
private:
    int m_hour;
    int m_min;
    int m_sec;
public:
    void SetTime(int hour, int min , int second)
    {
        m_hour = hour;
        m_min = min;
        m_sec = second;
        Notify();
    }
    int GetHour() {return m_hour ;}
    int GetMin() {return m_min ;}
    int GetSec() {return m_sec ;}

};


class DigitalClock : public Observer
{
private:
    Timer &Observable;
public:
    DigitalClock(Timer & timer) : Observable(timer)
    {
        Observable.Attach(*this);
    }
    ~DigitalClock()
    {
        Observable.Detach(*this);
    }
    void Draw()
    {
        std::cout << "Digital Time " 
        << Observable.GetHour()
        << ":"<< Observable.GetMin()
        << ":"<< Observable.GetSec();
    }
    void Update() override
    {
        Draw() ;
    }
};


class AnalogueClock : public Observer
{
private:
    Timer &Observable;
public:
    AnalogueClock(Timer & timer) : Observable(timer)
    {
        Observable.Attach(*this);
    }
    ~AnalogueClock()
    {
        Observable.Detach(*this);
    }
    void Draw()
    {
        std::cout << "Analogue Time " 
        << Observable.GetHour()
        << ":"<< Observable.GetMin()
        << ":"<< Observable.GetSec();
    }
    void Update() override
    {
        Draw() ;
    }
};



int main ()
{
    Timer timer;
    DigitalClock digital_clock(timer);
    timer.SetTime(12,34,00);

    return 0;
}