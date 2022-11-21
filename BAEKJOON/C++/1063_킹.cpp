#include <iostream>
using namespace std;

string move(string point, string cmd);

int main()
{
    string point_king;
    string point_stone;
    int n;
    cin >> point_king >> point_stone >> n;
    for (int i = 0; i < n; i++)
    {
        string cmd, king_tmp, stone_tmp;
        cin >> cmd;
        king_tmp = move(point_king, cmd);
        if (king_tmp == point_stone)
        {
            stone_tmp = move(point_stone, cmd);
            if (stone_tmp != point_stone)
            {
                point_king = king_tmp;
                point_stone = stone_tmp;
            }
        }
        else
        {
            point_king = king_tmp;
        }
    }
    cout << point_king << "\n"
         << point_stone;
    return 0;
}
string move(string point, string cmd)
{
    if (cmd == "R" && point[0] < 'H')
    {
        point[0] += 1;
    }
    else if (cmd == "L" && point[0] > 'A')
    {
        point[0] -= 1;
    }
    else if (cmd == "B" && point[1] > '1')
    {
        point[1] -= 1;
    }
    else if (cmd == "T" && point[1] < '8')
    {
        point[1] += 1;
    }
    else if (cmd == "RT" && point[0] < 'H' && point[1] < '8')
    {
        point[0] += 1;
        point[1] += 1;
    }
    else if (cmd == "LT" && point[0] > 'A' && point[1] < '8')
    {
        point[0] -= 1;
        point[1] += 1;
    }
    else if (cmd == "RB" && point[0] < 'H' && point[1] > '1')
    {
        point[0] += 1;
        point[1] -= 1;
    }
    else if (cmd == "LB" && point[0] > 'A' && point[1] > '1')
    {
        point[0] -= 1;
        point[1] -= 1;
    }
    return point;
}