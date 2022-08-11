#include "user.h"
#include <string.h>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

user::user()
{

}
void user::add_user()//getting info. of users
{
    cout << "Enter name: ";
    getline(cin, name);
    cout << "\n";

    cout << "Enter your E-mail: ";
    getline(cin, email);
    cout << "\n";

    cout << "Enter your telephone number: ";
    cin >> tel_num;
    cin.ignore();
}

void user::display_user()//displaying users' info
{
    cout << "The name of the user is: "<< name << endl;
    cout << "The telephone number is: " << tel_num << "\n";
    cout << "The E-mail is: " << email << "\n";
    //printf_vec_user(rented);

}

void user::search_by_name_user(string n, vector<user>u)//searching by name
{
    int y = 0;
    for(int i = 0; i < u.size(); i++)
    {
        if(n == u[i].name)
        {
            u[i].display_user();
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

void user::choose_by_name_user(string n, vector<user>u)//choosing user to rent to
{
    int y = 0;
    for(int i = 0; i < u.size(); i++)
    {
        if(n == u[i].name)
        {
            cout << "You have chosen " << u[i].name << endl;
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

