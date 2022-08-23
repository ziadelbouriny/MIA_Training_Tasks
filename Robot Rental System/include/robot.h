#ifndef ROBOT_H
#define ROBOT_H
#include <string.h>
#include <iostream>
#include <vector>
#define MAX 9

using namespace std;

class robot
{
public:
    string name;
    float price_day;
    bool rented = false;
    char func_id[MAX] = {0};
    vector <string> dates;
public:
    robot();
    void add_robot();
    void display_robot();
    void search_by_name_robot(string n, vector<robot>r);
    void push_vec_robot_date(string d, vector<robot>r);
    void choose_by_name_robot(string n, vector<robot>r);
};

#endif // ROBOT_H
