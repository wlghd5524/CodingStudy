#include <iostream>
#include <vector>
using namespace std;
int m[9][9] = {0};
vector<pair<int, int>> blank;
bool finish = false;
bool check(int a, int b)
{
    bool bit[10] = {false};
    for (int i = 0; i < 9; i++)
    {
        if(i == b) {
            continue;
        }
        if (m[a][i] == m[a][b])
        {
            return false;
        }
    }
    for(int i = 0;i<9;i++) {
        if(i == a) {
            continue;
        }
        if (m[i][b] == m[a][b])
        {
            return false;
        }
    }
    for (int i = a - (a % 3) ; i < a - (a % 3) + 3; i++)
    {
        for (int j = b - (b % 3); j < b - (b % 3) + 3; j++)
        {
            if (a == i && b == j)
            {
                continue;
            }
            if (m[i][j] == m[a][b])
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int n)
{
    if (n == blank.size())
    {
        finish = true;
        return;
    }
    int a = blank[n].first;
    int b = blank[n].second;
    for (int i = 1; i <= 9; i++)
    {
        m[a][b] = i;
        if (check(a, b))
        {
            solve(n + 1);
        }
        if (finish)
        {
            return;
        }
    }
    m[a][b] = 0;
    return;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (m[i][j] == 0)
            {
                blank.push_back(make_pair(i, j));
            }
        }
    }
    solve(0);
    cout << "\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}