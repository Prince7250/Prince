// 1) Given a date with three elements date, month & year, your task is to print the next date of it.
//  Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int leap_year(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
int main()
{
    int date, month, year;
    cin >> date >> month >> year;

    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leap_year(year))
    {
        month_days[1] = 29;
    }
    date++;
    if (date > month_days[month - 1])
    {
        date = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }

    cout << date << " " << month << " " << year;
    return 0;
}