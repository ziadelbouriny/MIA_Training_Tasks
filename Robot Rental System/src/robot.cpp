#include "robot.h"
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

robot::robot()
{

}
void robot::add_robot()
{
    cout << "Enter name: ";//getting name of robot
    getline(cin, name);
    cout << "\n";

    cout << "Enter renting price/day: ";//getting the rent price of robot
    cin >> price_day;

    int temp;
    cout << "Enter the number of functions of the robot: ";//getting the number of functions the robot have
    cin >> temp;

    while((temp < 1)||(temp > 5))//checking the entered number bet. 1 - 5 or not and if the i/p is wrong ask user to enter again
    {
        cout << "Enter the number of functions of the robot: ";
        cin >> temp;
    }
    cout << endl;
    cout << "Enter the function IDs(1 - 5):";//getting the function numbers
    for(int i = 0; i < ((temp*2)-1); i++)
    {
        cin >> func_id[i];
    }
    for(int i = 0; i < ((temp*2)-1); i+=2)//checking if any number is wrong then, ask to correct such the wrong one
    {
        if((func_id[i] < '1') || (func_id[i] > '5'))
        {
            cout << "Enter the function ID instead of wrong:";
            cin >> func_id[i];
            while((int)func_id[i] < 49 || (int)func_id[i] > 53)
            {
                cin >> func_id[i];
            }
        }
    }
    cin.ignore();
}
void robot:: display_robot()//function to display robot's info.
{
    cout << "The name of the robot is: "<< name << endl;

    cout << "The price of renting/day is: " << price_day << endl;

    cout << "Function IDs are: ";
    for(int i = 0; i < MAX; i+=2)
    {
        if(func_id[i] != 0)
        {
            cout << func_id[i] << " ";
        }
        else
        {
            break;
        }
    }
    cout << endl;
    //printf_vec_robot(dates);
    cout << endl;
}
void robot::search_by_name_robot(string n, vector<robot>r)//searching for robots by name
{
    int y = 0;
    for(int i = 0; i < r.size(); i++)
    {
        if(n == r[i].name)
        {
            r[i].display_robot();
            y = 0;
            break;
        }
        else
        {
            y = 1;
        }
    }
    if(y == 1)
    {
        cout << "Not found";
    }

}

void robot::push_vec_robot_date(string d, vector<robot>r)//pushing new date and trying to detect if robot is rented or not
{
    int y = 0;
    for(int j = 0; j < r.size(); j++)
    {
        cout << r[j].dates.size() << "\n";
        if(r[j].dates.size() < 1)
        {
            r[j].display_robot();
            r[j].dates.push_back(d);
        }
        else
        {
           for(int i = 0; i < r[j].dates.size(); i++)
           {
                if(d == r[j].dates[i])
                {
                    y = 0;
                    break;
                }
                else if (d != r[j].dates[i])
                {
                    y = 1;
                }
           }
           if(y == 1)
           {
                r[j].display_robot();
                r[j].dates.push_back(d);
           }
        }
    }

}

void robot::choose_by_name_robot(string n, vector<robot>r)//choosing by admin the robot to rent
{
    int y = 0;
    for(int i = 0; i < r.size(); i++)
    {
        if(n == r[i].name)
        {
            cout << "You have chosen " << r[i].name << endl;
            cout << "You have rented " <<  r[i].name << endl;
            r[i].rented = true;
            y = 0;
            break;
        }
        else
        {
            y = 1;
        }
    }
    if(y == 1)
    {
        cout << "Not found";
    }
}
