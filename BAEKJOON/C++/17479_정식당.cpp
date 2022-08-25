#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    bool okay = true;
    int normal, special, service, price, n;
    long int normal_sum = 0, sum = 0;
    bool is_ordered_sp = false;
    bool is_ordered_service = false;
    string name;
    cin >> normal >> special >> service;
    map<string, pair<string, int>> m;
    for (int i = 0; i < normal; i++) {
        cin >> name >> price;
        m[name] = {"normal", price};
    }
    for (int i = 0; i < special; i++) {
        cin >> name >> price;
        m[name] = {"special", price};
    }
    for (int i = 0; i < service; i++) {
        cin >> name;
        m[name] = {"service", 0};
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        if (m.find(name)->second.first == "normal") {
            normal_sum += m.find(name)->second.second;
            sum += m.find(name)->second.second;
        }
        else if (m.find(name)->second.first == "special") {
            is_ordered_sp = true;
            sum += m.find(name)->second.second;
        }
        else if (m.find(name)->second.first == "service") {
            if (is_ordered_service == true) {
                okay = false;
            }
            is_ordered_service = true;
        }
    }
    if (is_ordered_service == true) {
        if (sum < 50000) {
            okay = false;
        }
    }
    if (is_ordered_sp == true) {
        if (normal_sum < 20000) {
            okay = false;
        }
    }
    if (okay == true) {
        cout << "Okay";
    }
    else {
        cout << "No";
    }
}