#include<iostream>

using namespace std;

int main()
{
    int test, day, month, year, currentDay, currentMonth, currentYear;
    cin >> test;

    for(int i=0;i<test;i++)
    {
        cin >> currentDay >> currentMonth >> currentYear;
        cin >> day >> month >> year;

        if(currentMonth<month)
        {
            currentMonth+=12;
        }

    }
}
