#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    multimap<int, string> mm;
    for (int i = 0; i < n; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        mm.insert({b, a});
    }
    for (int i = 0; i < m; i++)
    {
        int p = 0;
        cin >> p;
        cout << mm.lower_bound(p)->second << "\n";
    }
    return 0;
}