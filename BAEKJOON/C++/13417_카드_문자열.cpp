#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        deque<char> str_dq;
        queue<char> cards;
        for (int j = 0; j < n; j++)
        {
            char tmp;
            cin >> tmp;
            cards.push(tmp);
        }
        str_dq.push_back(cards.front());
        cards.pop();
        while (!cards.empty())
        {
            if (str_dq.front() < cards.front())
            {
                str_dq.push_back(cards.front());
                cards.pop();
            }
            else
            {
                str_dq.push_front(cards.front());
                cards.pop();
            }
        }
        while (!str_dq.empty())
        {
            cout << str_dq.front();
            str_dq.pop_front();
        }
        cout << "\n";
    }
    return 0;
}