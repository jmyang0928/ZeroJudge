// AC (3ms, 356KB)
// Author: JMYANG
// Tag: math

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (b * b - 4 * a * c > 0)
        {
            cout << "Two different roots x1=" << (-b + sqrt(b * b - 4 * a * c)) / 2 / a << " , x2=" << (-b - sqrt(b * b - 4 * a * c)) / 2 / a << endl;
        }
        else if (b * b - 4 * a * c == 0)
        {
            cout << "Two same roots x=" << (-b + sqrt(b * b - 4 * a * c)) / 2 / a << endl;
        }
        else
        {
            cout << "No real root" << endl;
        }
    }
}