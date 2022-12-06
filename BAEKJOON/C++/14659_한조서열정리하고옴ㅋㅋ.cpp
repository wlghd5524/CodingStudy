#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int max_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] < v[j])
            {
                if (cnt > max_cnt)
                {
                    max_cnt = cnt;
                }
                break;
            }
            else
            {
                cnt++;
            }
            if (j + 1 == n)
            {
                if (cnt > max_cnt)
                {
                    max_cnt = cnt;
                }
            }
        }
    }
    cout << max_cnt;
}
