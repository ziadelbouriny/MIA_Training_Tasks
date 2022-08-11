#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include "robot.h"
#include "user.h"
using namespace std;

void printf_vec_robot(vector <robot> x)
{
    for(int i = 0; i < x.size(); i++)
    {
        x[i].display_robot();
    }
}
void printf_vec_user(vector <user> x)
{
    for(int i = 0; i < x.size(); i++)
    {
        x[i].display_user();
    }
}

int main()
{
    vector<robot>robots;
	vector<user>users;
    while (1)
    {
        int choice;
		cout << "What would you like to do:\n1-Add Robot\n2-Add User\n3-Display users\n4-Display robots\n5-Search for Robot\n6-Search for user\n7-Rent robot to user\n8-Exit\n";
		cin >> choice;
		cin.ignore();
		switch(choice)
		{
		case 1:
			 {
			     robot r1;
                 r1.add_robot();
                 robots.push_back(r1);
                 break;
			 }
        case 2:
            {
                 user u1;
                 u1.add_user();
                 users.push_back(u1);
                 break;
            }
        case 3:
            {
                 printf_vec_user(users);
                 break;
            }
		case 4:
		    {
                 printf_vec_robot(robots);
                 break;
		    }
        case 5:
            {
                string n;
                cout << "Search by name: ";
                cin >> n;
                robot r5;
                r5.search_by_name_robot(n, robots);
            }
        case 6:
            {
                string n;
                cout << "Search by name: ";
                cin >> n;
                user u5;
                u5.search_by_name_user(n, users);
            }
        case 7:
            {

                printf_vec_user(users);
                string n;
                cout << "Choose 1 user you want to rent to(by name): " << endl;
                getline(cin, n);
                user u5;
                u5.choose_by_name_user(n, users);
                string d;
                cout << "Please enter the date you want to rent at: " << endl;
                cin >> d;
                robot r5;
                r5.push_vec_robot_date(d, robots);
                string p;
                cout << "Please enter the robot you want to rent: " << endl;
                cin >> p;
                r5.choose_by_name_robot(p, robots);
                break;
            }
        case 8:
            {
                return 0;
            }
		}
    }
    return 0;
}
