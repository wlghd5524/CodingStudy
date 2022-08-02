#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    deque<int> dq;
    int t, n;
    string func;
    string arr;
    string tmp;
    cin >> t;
    for (int i = 0; i < t; i++) {
        bool rvs = false;
        bool error = false;
        cin >> func;
        cin >> n;
        cin >> arr;
        for (int j = 1; j < arr.size(); j++) {
            if (isdigit(arr[j]) != 0) {
                tmp += arr[j];
            }
            else {
                if (tmp.size() != 0) {
                    dq.emplace_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }
        for (int j = 0; j < func.size(); j++) {
            if (func[j] == 'R')
                rvs = !rvs;
            else if (func[j] == 'D') {
                if (dq.empty() == 1) {
                    cout << "error\n";
                    error = true;
                    break;
                }
                else {
                    if (rvs == false)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
            }
        }
        if (error == true)
            continue;
        cout << "[";
        if (rvs == false) {
            for (int j = 0; j < dq.size(); j++) {
                cout << dq[j];
                if (j != dq.size() - 1)
                    cout << ",";
            }
        }
        else {
            for (int j = dq.size() - 1; j >= 0; j--) {
                cout << dq[j];
                if (j != 0)
                    cout << ",";
            }
        }
        cout << "]\n";
        dq.clear();
    }
}
