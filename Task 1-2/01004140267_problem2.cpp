#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q = 0;
    cin >> q;
    int hp = 0, p = 0, h = 0;
    char *cases[q];
    for(int i = 0; i < q; i++)
    {
        cin >> hp >> p >> h;
        for(int j = 0; j < p; j++)
        {
            hp = floor(hp/2) + 10;
        }
        for(int k = 0; k < h; k++)
        {
            hp -= 10;
        }
        if(hp <= 0)
        {
            cases[i] = "YES";
        }
        else
        {
            cases[i] = "NO";
        }
    }
    for(int j = 0; j < q; j++)
    {
        cout << cases[j] << "\n";
    }
    return 0;
}
