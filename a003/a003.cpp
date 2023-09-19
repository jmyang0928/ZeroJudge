// AC (3ms, 320KB)
// Author: JMYANG
// Tag: switch

#include <iostream>
using namespace std;
int main()
{
    int M, D;
    while (cin >> M >> D)
    {
        switch ((M * 2 + D) % 3)
        {
        case 0:
            cout << "普通" << endl;
            break;
        case 1:
            cout << "吉" << endl;
            break;
        case 2:
            cout << "大吉" << endl;
            break;
        }
    }
}