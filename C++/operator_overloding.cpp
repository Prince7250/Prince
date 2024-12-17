#include <iostream>
using namespace std;
class time
{
    int hrs, mins;

public:
    void getTime(int h, int m)
    {
        hrs = h;
        mins = m;
    }
    friend time operator+(time t1, time t2);

    void putTime()
    {
        cout << hrs << " hrs " << mins << " mins " << endl;
    }

    // time operator+(time t2) {
    //     time temp;
    //     temp.mins = mins + t2.mins;
    //     temp.hrs = hrs + t2.hrs ;

    // }
};

time operator+(time t1, time t2)
{
    time temp;
    temp.hrs = t1.hrs + t2.hrs;
    temp.mins = t1.mins + t2.mins;
    return temp;
}

int main()
{
    time t1, t2, t3;
    t1.getTime(4, 50);
    t2.getTime(5, 06);
    t3 = t1 + t2;
    t1.putTime();
    t2.putTime();
    t3.putTime();
    return 0;
}