#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> price;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        price.push_back(p);
    }
    sort(price.begin(), price.end(), greater<>());
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 2)
        {
            continue;
        }
        result += price[i];
    }
    cout << result;
    return 0;
}