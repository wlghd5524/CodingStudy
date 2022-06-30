#include <iostream>
#include <string>
#include <map>
using namespace std;
struct Site
{
    string url;
    string pw;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    Site site[n];
    string srch[m];
    map<string, string> si;
    for (int i = 0; i < n; i++) {
        cin >> site[i].url >> site[i].pw;
        si.insert({site[i].url, site[i].pw});
    }
    for (int i = 0; i < m; i++)
        cin >> srch[i];
    for (int i = 0; i < m; i++) {
        if (si.find(srch[i]) != si.end())
            cout << si.find(srch[i])->second << "\n";
    }
    return 0;
}