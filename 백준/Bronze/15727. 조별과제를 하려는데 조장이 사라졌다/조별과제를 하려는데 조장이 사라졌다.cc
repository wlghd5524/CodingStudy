#include <iostream>
using namespace std;
int main()
{
    int l;
    cin >> l;
    int result = l / 5;
    l %= 5;
    if (l != 0)
    {
        result++;
    }
    cout << result;
    return 0;
}