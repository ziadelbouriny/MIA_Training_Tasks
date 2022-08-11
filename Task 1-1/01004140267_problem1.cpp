#include <iostream>

using namespace std;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        if(i == 0)
        {
            cout << "*" << "    " << "*" << "  " << "*****";
        }
        else if(i == 2)
        {
            cout << "******" << "    " << "*";
        }
        else if(i == 4)
        {
            cout << "*" << "    " << "*" << "  " << "*****";
        }
        else
        {
            cout << "*" << "    " << "*" << "    " << "*";
        }
        cout << "\n";
    }
    return 0;
}
