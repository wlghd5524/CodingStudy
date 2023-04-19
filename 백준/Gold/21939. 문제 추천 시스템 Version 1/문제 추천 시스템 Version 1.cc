#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    multiset<pair<int, int>> diff_ms;
    map<int, int> num_mm;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num, difficult;
        cin >> num >> difficult;
        diff_ms.insert({difficult, num});
        num_mm[num] = difficult;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string cmd;
        int num;
        cin >> cmd >> num;
        if (cmd == "add")
        {
            int difficult;
            cin >> difficult;
            diff_ms.insert({difficult, num});
        }
        else if (cmd == "recommend")
        {
            if (num == 1)
            {
                cout << prev(diff_ms.end())->second << "\n";
            }
            else if (num == -1)
            {
                cout << diff_ms.begin()->second << "\n";
            }
        }
        else if (cmd == "solved")
        {
            diff_ms.erase({num_mm[num], num});
        }
    }
}