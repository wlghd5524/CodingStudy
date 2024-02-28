#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, L;
    cin >> N >> L;
    vector<int> height;
    for (int i = 0; i < N; i++)
    {
        int h;
        cin >> h;
        height.push_back(h);
    }
    sort(height.begin(), height.end());
    for (int i = 0; i < height.size(); i++)
    {
        if (height[i] <= L)
        {
            L += 1;
        }
        else
        {
            break;
        }
    }
    cout << L;
    return 0;
}