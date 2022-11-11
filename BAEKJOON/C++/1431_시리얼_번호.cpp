#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(string a, string b)
{
    if (a.size() == b.size())
    {
        int a_sum = 0, b_sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (isdigit(a[i]))
            {
                a_sum += a[i] - '0';
            }
            if (isdigit(b[i]))
            {
                b_sum += b[i] - '0';
            }
        }
        if (a_sum == b_sum)
        {
            return a < b;
        }
        return a_sum < b_sum;
    }
    return a.size() < b.size();
}
int main()
{
    int n;
    cin >> n;
    vector<string> guitars(n);
    for (int i = 0; i < n; i++)
    {
        cin >> guitars[i];
    }
    sort(guitars.begin(), guitars.end(), cmp);
    for (int i = 0; i < guitars.size(); i++)
    {
        cout << guitars[i] << "\n";
    }
}