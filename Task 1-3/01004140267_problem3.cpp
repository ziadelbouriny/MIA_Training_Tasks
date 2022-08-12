#include <bits/stdc++.h>

/* ASCII Code of '1' -> 49 and 'a' -> 97
 then, to decode any number into a letter we should
 add to the ASCII code of the number 48*/

using namespace std;

int main()
{
    int q;
    char c;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++)
        {
            if(s[j+2] == '&')//checking if number contains '&'
            {
                if(s[j] == '1')//numbers divided into 2 parts tens and twenties as tens rep. from j -> s and twenties the rest
                {
                    c = s[j+1] + 58;//if it's tens then add 58 to reach the desired letter
                    cout << c;
                }
                else if(s[j] == '2')
                {
                    char c = s[j+1] + 68;//if it's twenties then add 68 to reach the desired letter
                    cout << c;
                }
                j += 2;//jump 2 indexes to check the next '&'
            }
            else
            {
                c = s[j] + 48;//if it's clear from '&' then it just needs 48 to reach the desired letter
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}
