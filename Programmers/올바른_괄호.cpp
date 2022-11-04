#include <string>
#include <iostream>
#include <stack>

using namespace std;

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