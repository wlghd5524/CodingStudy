#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, tmp;
    cin >> n;
    stack<pair<int, int>> st;
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (!st.empty())
        {
            while (tmp > st.top().first)
            {
                result[st.top().second] = tmp;
                st.pop();
                if (st.empty())
                {
                    break;
                }
            }
        }
        st.push({tmp, i});
    }
    while (!st.empty())
    {
        result[st.top().second] = -1;
        st.pop();
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}