#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Subject;

class Observer
{
public:
    virtual ~Observer() = default ;
    virtual void Update(Subject&) = 0 ;
};


class Subject
{
public:
    virtual ~Subject() = default;
    void Attach(Observer& o)
    {
        observers.push_back(&o);
    }

    void Detach(Observer &o)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), &o));
    }

    void Notify()
    {
        for (auto *o : observers)
        {
            o->Update(*this);
        }
    }

private:
    std::vector<Observer*> observers;
};


class ClockTimer : public Subject
{
public:
    void SetTime(int Hour, int min, int sec)
    {
        this->hour   = Hour;
        this->minute = min;
        this->second = sec;
        
        Notify();
    }
    int GetHour() const {return hour;}
    int GetMin()  const {return minute;}
    int Getsec()  const {return second;}

private:
    int hour;
    int minute;
    int second;
};


class DigitalClock : public Observer
{
public:
    explicit DigitalClock(ClockTimer& o) : subject(o)
    {
        subject.Attach(*this);
    }
    ~DigitalClock()
    {
        subject.Detach(*this);
    }
    void Update(Subject& TheChangedSubject) override
    {
        if(&TheChangedSubject == &subject)
        {
            Draw();
        }
    }
    void Draw()
    {
        int hour = subject.GetHour();
        int minute = subject.GetMin();
        int second = subject.Getsec();
        std::cout << "Digital time is " << hour << ":"
                  << minute << ":"
                  << second << std::endl ;
    }

private:
    ClockTimer& subject;
};


class AnalogClock : public Observer
{
public:
    explicit AnalogClock(ClockTimer& o) : subject(o)
    {
        subject.Attach(*this);
    }
    ~AnalogClock()
    {
        subject.Detach(*this);
    }
    void Update(Subject& TheChangedSubject) override
    {
        if(&TheChangedSubject == &subject)
        {
            Draw();
        }
    }
    void Draw()
    {
        int hour = subject.GetHour();
        int minute = subject.GetMin();
        int second = subject.Getsec();
        std::cout << "Analog time is " << hour << ":"
                  << minute << ":"
                  << second << std::endl ;
    }

private:
    ClockTimer& subject;
};




int main ()
{
    ClockTimer timer;
    DigitalClock digitalClock(timer);
    AnalogClock analogClock(timer);

    timer.SetTime(14, 32 , 45) ;

    return 0;
}