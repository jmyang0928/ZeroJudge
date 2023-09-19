// AC (3ms, 336KB)
// Author: JMYANG
// Tag: map

#include <iostream>
#include <map>
using namespace std;

map<char, int> city = {{'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17}, {'I', 34}, {'J', 18}, {'K', 19}, {'L', 20}, {'M', 21}, {'N', 22}, {'O', 35}, {'P', 23}, {'Q', 24}, {'R', 25}, {'S', 26}, {'T', 27}, {'U', 28}, {'V', 29}, {'W', 32}, {'X', 30}, {'Y', 31}, {'Z', 33}};

int main()
{
    string a;
    int sum;
    int temp;
    while (cin >> a)
    {
        sum = 0;
        sum += city[a[0]] / 10;
        sum += city[a[0]] % 10 * 9;
        for (int i = 1; i <= 8; i++)
        {
            sum += (((int)a[i]) - 48) * (9 - i);
        }
        sum += ((int)a[9]) - 48;
        if (sum % 10 == 0)
        {
            cout << "real" << endl;
        }
        else
        {
            cout << "fake" << endl;
        }
    }
}