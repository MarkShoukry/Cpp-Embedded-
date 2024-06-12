#include <iostream>
using namespace std;

class serial
{
public:
                                // initalizer list
    explicit serial (uint16_t baud_rate) : mBaud_Rate(baud_rate)
    {
        cout << "Setting Baud Rate: " << mBaud_Rate << endl;

    }
private :
    uint16_t mBaud_Rate;

};


int main ()
{
    serial serialOne(99);


    return 0;
}