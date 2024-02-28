#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int TestCase;
    cin >> TestCase;
    vector<int> price;
    while (TestCase--)
    {
        int p = 1, result = 0;
        bool expensive = false;
        while (1)
        {
            cin >> p;
            if (p == 0)
            {
                break;
            }
            price.push_back(p);
        }
        sort(price.begin(), price.end(), greater<>());
        for (int i = 0; i < price.size(); i++)
        {
            result += (2 * (pow(price[i], i + 1)));
            if (result > 5000000)
            {
                expensive = true;
                break;
            }
        }
        price.clear();
        if(expensive) {
            cout << "Too expensive\n";
        }
        else {
            cout << result << "\n";
        }
    }
    return 0;
}