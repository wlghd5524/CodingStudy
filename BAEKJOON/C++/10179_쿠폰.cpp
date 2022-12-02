#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        double n;
        cin >> n;
        cout << fixed;
        cout.precision(2);
        cout << "$" << n * 80 / 100 << "\n";
    }
}