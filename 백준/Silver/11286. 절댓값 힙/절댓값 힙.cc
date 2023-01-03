#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
struct cmp
{
    bool operator()(int a, int b) {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, data;
    cin >> n;
    priority_queue<int, vector<int>, cmp> q;
    for (int i = 0; i < n; i++) {
        cin >> data;
        if (data != 0)
            q.push(data);
        else {
            if (q.empty() == 1)
                cout << "0\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }
}