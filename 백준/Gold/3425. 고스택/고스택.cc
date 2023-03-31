#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    while (1)
    {
        const int MAX = 1000000000;
        vector<string> commands;
        while (1)
        {
            string command;
            getline(cin, command);
            if (command == "")
            {
                continue;
            }
            if (command == "QUIT")
            {
                return 0;
            }
            else if (command == "END")
            {
                break;
            }
            else
            {
                commands.push_back(command);
            }
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            bool error = false;
            int ins;
            cin >> ins;
            stack<int> st;
            st.push(ins);
            for (int j = 0; j < commands.size(); j++)
            {

                if (commands[j] == "POP")
                {
                    if (st.size() == 0)
                    {
                        error = true;
                        break;
                    }
                    st.pop();
                }
                else if (commands[j] == "INV")
                {
                    if (st.size() == 0)
                    {
                        error = true;
                        break;
                    }
                    int tmp = -st.top();
                    st.pop();
                    st.push(tmp);
                }
                else if (commands[j] == "DUP")
                {
                    if (st.size() == 0)
                    {
                        error = true;
                        break;
                    }
                    st.push(st.top());
                }
                else if (commands[j] == "SWP")
                {
                    if (st.size() <= 1)
                    {
                        error = true;
                        break;
                    }
                    int tmp1 = st.top();
                    st.pop();
                    int tmp2 = st.top();
                    st.pop();
                    st.push(tmp1);
                    st.push(tmp2);
                }
                else if (commands[j] == "ADD")
                {
                    if (st.size() <= 1)
                    {
                        error = true;
                        break;
                    }
                    int tmp1 = st.top();
                    st.pop();
                    int tmp2 = st.top();
                    st.pop();
                    if (abs(tmp1 + tmp2) > MAX)
                    {
                        error = true;
                        break;
                    }
                    st.push(tmp1 + tmp2);
                }
                else if (commands[j] == "SUB")
                {
                    if (st.size() <= 1)
                    {
                        error = true;
                        break;
                    }
                    int tmp1 = st.top();
                    st.pop();
                    int tmp2 = st.top();
                    st.pop();
                    if (abs(tmp1 - tmp2) > MAX)
                    {
                        error = true;
                        break;
                    }
                    st.push(tmp2 - tmp1);
                }
                else if (commands[j] == "MUL")
                {
                    if (st.size() <= 1)
                    {
                        error = true;
                        break;
                    }
                    long long int tmp1 = st.top();
                    st.pop();
                    long long int tmp2 = st.top();
                    st.pop();

                    long long int tmp3 = tmp1 * tmp2;
                    to_string(tmp3);
                    if (abs(tmp3) > MAX)
                    {
                        error = true;
                        break;
                    }
                    st.push(tmp1 * tmp2);
                }
                else if (commands[j] == "DIV")
                {
                    if (st.size() <= 1)
                    {
                        error = true;
                        break;
                    }
                    int tmp1 = st.top();
                    if (tmp1 == 0)
                    {
                        error = true;
                        break;
                    }
                    st.pop();
                    int tmp2 = st.top();
                    st.pop();
                    st.push(tmp2 / tmp1);
                }
                else if (commands[j] == "MOD")
                {
                    if (st.size() <= 1)
                    {
                        error = true;
                        break;
                    }
                    int tmp1 = st.top();
                    if (tmp1 == 0)
                    {
                        error = true;
                        break;
                    }
                    st.pop();
                    int tmp2 = st.top();
                    st.pop();
                    st.push(tmp2 % tmp1);
                }
                else
                {
                    int num = stoi(commands[j].substr(4));
                    st.push(num);
                }
            }
            if (st.size() != 1)
            {
                error = true;
            }
            if (error)
            {
                cout << "ERROR\n";
            }
            else
            {
                cout << st.top() << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}