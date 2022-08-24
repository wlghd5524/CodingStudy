#include <iostream>
#include <map>
using namespace std;
int main() {
    int n, player, score = 0;
    cin >> n >> player;
    int win,lose,goal;
    cin >> win >> lose >> goal;
    map<string, char> m;
    bool success = false;
    string name;
    char ability;
    for(int i = 0; i < player; i++) {
        cin >> name >> ability;
        m[name] = ability;
    }
    for(int i = 0; i < n; i++) {
        cin >> name;
        if(m.find(name) != m.end()) {
            if(m[name] == 'W') {
                score += win;
            }
            else if(m[name] == 'L') {
                score -= lose;
            }
        }
        else {
            score -= lose;
        }
        if(score < 0) {
            score = 0;
        }
        if(score >= goal) {
            success = true;
        }
    }
    if(success == true) {
        cout << "I AM NOT IRONMAN!!";
    }
    else {
        cout << "I AM IRONMAN!!";
    }
}