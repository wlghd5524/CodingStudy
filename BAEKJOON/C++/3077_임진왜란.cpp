#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string name;
    vector<string> write(n);
    map<string, int> answer;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        answer[name] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> write[i];
    }
    int all_cnt = 0;
    int correct_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (answer[write[i]] < answer[write[j]])
            {
                correct_cnt++;
            }
            all_cnt++;
        }
    }
    cout << correct_cnt << "/" << all_cnt;
}