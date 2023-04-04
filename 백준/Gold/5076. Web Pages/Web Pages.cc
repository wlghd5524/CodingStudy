#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    while (1)
    {
        stack<string> st;
        getline(cin, s);
        if (s == "#")
        {
            break;
        }
        bool parsing = false;
        bool close_tag = false;
        string tmp;
        for (int i = 0; i < s.size(); i++)
        {
            char si = s[i];
            if (s[i] == '>' && parsing)
            {
                parsing = false;
                if (close_tag && !st.empty())
                {
                    tmp.erase(0, 1);
                    if (tmp == st.top())
                    {
                        st.pop();
                        close_tag = false;
                    }
                }
                else
                {
                    st.push(tmp);
                }
                tmp = "";
            }
            if (parsing)
            {
                if (s[i] == '/')
                {
                    close_tag = true;
                }
                tmp.push_back(s[i]);
            }
            if (tmp == "a href")
            {
                parsing = false;
                st.push("a");
                tmp = "";
            }
            if (s[i] == '<')
            {
                parsing = true;
            }
        }
        if (st.empty())
        {
            cout << "legal\n";
        }
        else
        {
            cout << "illegal\n";
        }
    }
    return 0;
}