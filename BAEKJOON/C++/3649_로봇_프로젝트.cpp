#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        int x;
        cin >> x;
        int n;
        cin >> n;
        if (cin.eof())
        {
            break;
        }
        vector<int> blocks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> blocks[i];
        }
        if (n <= 1)
        {
            cout << "danger" << "\n";
            continue;
        }
        sort(blocks.begin(), blocks.end());
        int a = 0;
        int b = n - 1;
        pair<int, int> result;
        bool is_possible = true;
        while (1)
        {
            if (blocks[a] + blocks[b] == x * 10000000)
            {
                result = {blocks[a], blocks[b]};
                break;
            }
            else if (blocks[a] + blocks[b] < x * 10000000)
            {
                a++;
            }
            else if (blocks[a] + blocks[b] > x * 10000000)
            {
                b--;
            }
            if (a >= b)
            {
                is_possible = false;
                break;
            }
        }
        if (is_possible)
        {
            cout << "yes " << result.first << " " << result.second << "\n";
        }
        else
        {
            cout << "danger" << "\n";
        }
    }
    return 0;
}