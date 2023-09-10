/*Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.*/
#include <iostream>
using namespace std;
class Date
{
private:
    int day, month, year;
public:
    Date(int day = 1, int month = 1, int year = 2000) : day(day), month(month), year(year) {}
    // Prefix increment operator
    Date &operator++()
    {
        // Check if it's the last day of the month
        int lastDay = 31;
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                lastDay = 29;
            }
            else
            {
                lastDay = 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            lastDay = 30;
        }

        if (day == lastDay)
        {
            day = 1;
            if (month == 12)
            {
                month = 1;
                year++;
            }
            else
            {
                month++;
            }
        }
        else
        {
            day++;
        }

        return *this;
    }

    // Postfix increment operator
    Date operator++(int)
    {
        Date temp(*this);
        ++(*this);
        return temp;
    }

    // Display function to print the date
    void display() const
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
int main()
{
    Date d(14, 11, 2021);

    cout << "Original date: ";
    d.display();

    cout << "Prefix increment: ";
    (++d).display();

    cout << "Postfix increment: ";
    (d++).display();

    cout << "Final date: ";
    d.display();

    return 0;
}