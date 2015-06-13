#include <iostream>
#include <string.h>
#include <iomanip>
#include <time.h>

using namespace std;

struct item
{
    string name;
    float price;
    int index;
} apples = {"4 lbs Apples" , 25, 1}, oranges = {"4 lbs Apples" , 30, 2};

void sleep(unsigned int m_seconds)
{
    clock_t goal = m_seconds + clock();
    while (goal > clock());
}

bool finished_scanning()
{
    while (true)
    {
        char sel[1];
        cout << "Are you finished scanning? (y/n): ";
        cin >> sel;

        if (stricmp("Y", sel) == 0 || stricmp("y", sel) == 0)
            return false;
        else if (stricmp("N", sel) == 0 || stricmp("n", sel) == 0)
            return true;
        else
            cout << "Invalid selection." << endl;
    }
}

float calc_change(float total, float cash)
{
    return (cash - total);
}

int main()
{
    float cash_register;
    bool _register = true;
    bool scan = true;
    bool pay = true;
    int sel;
    float total = 0;
    float cash;
    float change;

    while (_register == true)
    {
        cout << "How much money is in the register?" << endl
            << " $";
        cin >> cash_register;

        if (cash_register >= 0) {
            cout << setprecision(2) << fixed << "Cash in register: $" << cash_register << endl;
            _register = false;
        }
        else {
            cout << "You have entered an invalid amount, please try again..." << endl;
            _register = true;
        }
    }

    while (scan == true)
    {
        cout << "\nSelect an item from the list:" << endl
            << " 1. 4 lbs Apples: $" << apples.price << endl
            << " 2. 5 lbs Oranges: $" << oranges.price << endl
            << "\nSelection: ";
        cin >> sel;

        if (sel == 1) {
            total += apples.price;
            scan = finished_scanning();
        }
        else if (sel == 2) {
            total += oranges.price;
            scan = finished_scanning();
        }
        else {
            cout << "You have entered an invalid item." << endl;
            sleep(2000);
            scan = true;
        }
    }

    while (pay == true)
    {
        cout << setprecision(2) << fixed << "Balance Due: $" << total << endl
            << "Cash: $";
        cin >> cash;

        if (cash >= total) {
            change = calc_change(total, cash);
            if (change < cash_register)
            {
                cash_register = (cash_register - change) + cash;
                cout << setprecision(2) << fixed << "Change Due: $" << change << endl
                    << "Cash remaining in register: $" << cash_register << endl;
                cout << "Have a wonderful day!" << endl;
            }
            else {
                cout << "Oops! There is not enough money in the register!" << endl;
            }
            pay = false;
        }
        else {
            cout << "Insufficient Funds, try again..." << endl;
            sleep(2000);
            pay = true;
        }
    }

    return 0;
}
