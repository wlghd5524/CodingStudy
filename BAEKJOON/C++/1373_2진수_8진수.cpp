#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int count = 0, sum = 0;
    string str, result;
    cin >> str;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            sum += pow(2, count);
        }
        if (count == 2 || i == 0)
        {
            result.push_back(sum + '0');
            count = 0;
            sum = 0;
            continue;
        }

        count++;
    }
    reverse(result.begin(), result.end());
    cout << result;
}