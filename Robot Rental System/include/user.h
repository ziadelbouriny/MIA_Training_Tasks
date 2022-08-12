#ifndef USER_H
#define USER_H
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class user
{
public:
    string name;
    string tel_num;
    string email;
public:
    user();
    void add_user();
    void display_user();
    void search_by_name_user(string n, vector<user>u);
    void choose_by_name_user(string n, vector<user>u);
};

#endif // USER_H
