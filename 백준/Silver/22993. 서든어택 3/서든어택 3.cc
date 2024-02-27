#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> enemyAttack;
    int n;
    long long int playerAttack;
    cin >> n;
    cin >> playerAttack;
    for (int i = 0; i < n - 1; i++)
    {
        int attack = 0;
        cin >> attack;
        enemyAttack.push_back(attack);
    }
    sort(enemyAttack.begin(), enemyAttack.end());
    for (int i = 0; i < n - 1; i++)
    {
        int currentEnemyAttack = enemyAttack[i];
        if (currentEnemyAttack < playerAttack)
        {
            playerAttack += currentEnemyAttack;
        }
        else
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}