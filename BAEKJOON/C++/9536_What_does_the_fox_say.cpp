#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string record;
    string tmp;
    vector<string> crying;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        getline(cin, record);
        for (int j = 0;; j++) {
            getline(cin, tmp);
            crying.emplace_back(tmp);
            if (crying[j] == "what does the fox say?")
                break;
            for (int p = 0; p < crying[j].size(); p++) {
                if (crying[j][p] == ' ') {
                    crying[j].erase(0, p + 6);
                    break;
                }
            }
        }
        for (int j = 0; j < 100; j++) {
            for (int p = 0; p < crying.size(); p++) {
                if (record.find(" " + crying[p] + " ") != string::npos) {
                    record.erase(record.find(crying[p]), crying[p].size() + 1);
                    break;
                }
                if (record.find(" " + crying[p]) != string::npos && record.find(" " + crying[p]) + crying[p].size() + 1 == record.size()) {
                    record.erase(record.find(crying[p]), crying[p].size() + 1);
                    break;
                }
                if (record.find(crying[p] + " ") != string::npos && record.find(crying[p]) == 0) {
                    record.erase(0, crying[p].size() + 1);
                    break;
                }
            }
        }
        cout << record << "\n";
        record.clear();
        crying.clear();
    }
    return 0;
}