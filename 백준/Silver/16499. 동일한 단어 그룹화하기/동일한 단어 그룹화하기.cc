#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    set<string> group;
    while (N--)
    {
        string word;
        cin >> word;
        sort(word.begin(), word.end());
        group.insert(word);
    }
    cout << group.size();
    return 0;
}