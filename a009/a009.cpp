// AC (2ms, 320KB)
// Author: JMYANG
// Tag: string processing

#include <iostream>
using namespace std;

int main()
{
    string a;
    while (cin >> a)
    {
        for (int i = 0; i < a.length(); i++)
        {
            a[i] -= 7;
        }
        cout << a << endl;
    }
}