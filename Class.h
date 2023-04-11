/*
 * Clocks Code
 *
 *  Date: 3/13/2023
 *  Name: Brian Roche-Campos
 */

#include<bits/stdc++.h>
using namespace std;

// Time class 
class Time
{
public:
    int h1, h2, m1, m2, s1, s2;

    // There is a default constructor here.
    // Two clock formats are available: 12-hour and 24-hour.
    Time()
    {
        this->h1 = 12;
        this->h2 = 00;
        this->m1 = 00;
        this->m2 = 00;
        this->s1 = 00;
        this->s2 = 00;
    }

    // Each action is checked for a time limit.
    // The number of seconds and minutes should not exceed 60.
    void managetime(int t = 1)
    {
        if (t == 1)
        {
            if (s1 / 60 > 0)
            {
                s1 %= 60;
                m1++;
            }
            if (m1 / 60 > 0)
            {
                m1 %= 60;
                h1++;
            }
            if (h1 / 12 > 0)
            {
                h1 %= 12;
                if (h1 == 0)
                    h1 = 12;
            }
        }
        if (t == 2)
        {
            if (s2 / 60 > 0)
            {
                s2 %= 60;
                m2++;
            }
            if (m2 / 60 > 0)
            {
                m2 %= 60;
                h2++;
            }
            if (h2 / 24 > 0)
            {
                h1 %= 24;
            }
        }

    }
    // This function adds one second.
    void addSecond()
    {
        s1++;
        s2++;
        managetime(1);
        managetime(2);
    }

    // This is the function for waiting one second.
    void waitSecond()
    {
        s1++;
        s2++;
        managetime(1);
        managetime(2);
    }

    // This is the function to add one minute.
    void addMinute()
    {
        m1++;
        m2++;
        managetime(1);
        managetime(2);
    }

    // This is the function to add one hour.
    void addHour()
    {
        h1++;
        h2++;
        managetime(1);
        managetime(2);
    }

    // Using this function, you can display both times.
    void display()
    {
        printf("\nTime 1: %02d:%02d:%02d\n", h1, m1, s1);
        printf("Time 2: %02d:%02d:%02d\n\n", h2, m2, s2);
    }
};

int main()
{
    Time t;
    int p, n, m, f = 1;


    // The menu is as shown in the flowchart provided.
    while (f > 0)
    {
        t.display();
        cout << "Press Button? (1:yes, 2:no): " << endl;
        cin >> p;
        if (p == 1)
        {
            cout << "Choose option\n1. Add Time\n2. EXIT\nEnter 1 or 2: ";
            cin >> n;

            if (n == 1)
            {
                cout << "Choose option\n1. Add 1 hour\n2. Add 1 minute\n3. Add 1 second\nEnter 1 or 2 or 3: ";
                cin >> m;

                switch (m)
                {
                case 1: t.addHour(); break;
                case 2: t.addMinute(); break;
                case 3: t.addSecond();
                }
            }
            if (n == 2)
            {
                f = -1;
            }
        }
        else if (p == 2)
        {
            t.addSecond();
            t.waitSecond();
        }
    }
}
