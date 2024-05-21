#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int houseCount = 0;
vector<string> map;
bool isVisited[25][25] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y)
{
    isVisited[x][y] = true;
    houseCount++;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
        {
            if (!isVisited[nextX][nextY] && map[nextX][nextY] == '1')
                dfs(nextX, nextY);
        }
    }
}

int main()
{
    int result = 0;
    cin >> N;
    vector<int> house;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        map.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '1' && !isVisited[i][j])
            {
                dfs(i, j);
                result++;
                house.push_back(houseCount);
                houseCount = 0;
            }
        }
    }
    sort(house.begin(), house.end());
    cout << result << "\n";
    for (int i = 0; i < house.size(); i++)
        cout << house[i] << "\n";
    return 0;
}