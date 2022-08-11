#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int y = 0; y < q; y++)
    {
        int n;
        cin >> n;
        int height[n];
        int arr[n] = {0};
        for(int j = 0; j < n; j++)
        {
            cin >> height[j];
        }
        for(int i = 0; i < n; i++)
        {
            if(i == (n-1))//if it's the last creature then it'll see nothing
            {
                arr[i] = 0;
            }
            else if((i == (n-2)) || (height[i] < height[i+1]))// if it's before the last one or it's shorter than the next then, it'll see just 1
            {
                arr[i] = 1;
            }
            else if(height[i] > height[i+1])//if it's taller than the next then it has many possibilities
            {
                arr[i]=1;
                for(int k = (i+1); k < (n-1); k++)//looping on each creature after the used one
                {
                    if(height[k] < height[k+1])
                    {
                        if(height[i] < height[k+1])
                        {
                            arr[i]++;
                            break;
                        }
                        else if(height[i] > height[k+1])
                        {
                            arr[i]++;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        for(int u = 0; u < n; u++)
        {
            cout << arr[u] << " ";
        }
    }
    return 0;
}
