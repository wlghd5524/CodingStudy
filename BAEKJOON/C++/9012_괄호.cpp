#include <iostream>
#include <stack>

using namespace std;

bool solution(string s);

int main()
{
    int t;
    cin >> t;
    string str;
    for (int i = 0; i < t; i++)
    {
        bool is_correct = true;
        cin >> str;
        is_correct = solution(str);
        if (is_correct)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
bool solution(string s)
{
    stack<char> st;
    bool answer = true;

    if (s.size() % 2 != 0)
    {
        answer = false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                answer = false;
                break;
            }
            st.pop();
        }
    }
    if (!st.empty())
    {
        answer = false;
    }
    return answer;
}