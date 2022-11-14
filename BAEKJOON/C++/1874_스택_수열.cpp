#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 1;
    bool no = false;
    vector<char> result;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        while (cnt <= tmp)
        {
            st.push(cnt);
            result.push_back('+');
            cnt++;
        }

        if (st.top() == tmp)
        {
            result.push_back('-');
            st.pop();
        }
        else
        {
            no = true;
        }
    }
    if (no)
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}