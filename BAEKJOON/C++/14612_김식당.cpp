#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sort_cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "order") {
            int num, time;
            cin >> num >> time;
            v.push_back({num, time});
        }
        else if (cmd == "sort") {
            sort(v.begin(), v.end(), sort_cmp);
        }
        else {
            int num;
            cin >> num;
            auto iter = find_if(v.begin(), v.end(), [&num](const pair<int, int> &element)
                                { return element.first == num; });
            v.erase(iter);
        }
        for (int j = 0; j < v.size(); j++) {
            cout << v[j].first << " ";
        }
        if (!v.empty()) {
            cout << "\n";
        }
        else {
            cout << "sleep\n";
        }
    }
    return 0;
}