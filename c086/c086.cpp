// AC (3ms, 324KB)
//  Author: JMYANG
#include <iostream>
#include <vector>
using namespace std;

int N, X, selection = 0, curCard, curIdx; // N:總人數。X:最後剩餘人數。selection:紀錄測資筆數。curCard:目前的撲克牌。curIdx:篩選時要淘汰的index。
vector<short> people;                     // people:初始代表所有的人，隨著篩選逐漸減少。
int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> N >> X)
    {
        selection++;
        people.resize(N);
        for (int i = 0; i < N; i++)
            people[i] = i;
        for (int i = 0; i < 20; i++)
        {
            cin >> curCard;
            if (people.size() == X)
                continue; // 若目前剩餘人數等於最後剩餘人數，則不再繼續篩選，但還是要將測資讀完，以免影響下一組測資。
            // 第一次因為題目數數方式從1開始數，但程式people.begin()+0才是第一位，因此需要curIdx=curCard-1。
            // 第二次以後因為每次篩選都會移除一個元素，每次curIdx+curCard後都要-1，因此可以直接寫成--curCard。
            curIdx = --curCard;
            while (people.size() > X && curIdx < people.size())
            {
                people.erase(people.begin() + curIdx);
                curIdx += curCard;
            }
        }
        cout << "Selection #" << selection << endl;
        for (int p : people)
            cout << p + 1 << " ";
        cout << endl
             << endl;
    }
}