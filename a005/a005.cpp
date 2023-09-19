// AC (2ms, 312KB)
// Author: JMYANG
// Tag: math

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    int num[5];
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> num[i];
        }
        if (num[1] - num[0] == num[3] - num[2])
        {
            num[4] = num[3] * 2 - num[2];
        }
        else
        {
            num[4] = pow(num[3], 2) / num[2];
        }
        for (int i = 0; i < 5; i++)
        {
            cout << num[i] << " ";
        }
        cout << endl;
    }
}