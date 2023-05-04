#include <iostream>
#include <vector>
#include <math.h>
#define MAX 100000
using namespace std;
int n, m;
long long int arr[MAX];
vector<pair<long long int, int>> segmentTree;
pair<long long int, int> makeSegmentTree(int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node] = {arr[start], start};
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = min(makeSegmentTree(node * 2, start, mid), makeSegmentTree(node * 2 + 1, mid + 1, end));
}
pair<long long int, int> update(int node, int start, int end, int index, int value)
{
    if (index < start || index > end)
    {
        return segmentTree[node];
    }
    if (start == end)
    {
        return segmentTree[node] = {value, segmentTree[node].second};
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = min(update(node * 2, start, mid, index, value), update(node * 2 + 1, mid + 1, end, index, value));
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    segmentTree.resize(treeSize);
    makeSegmentTree(1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        long long int cmd, a, b;
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> a >> b;
            update(1, 0, n - 1, a - 1, b);
            arr[a - 1] = b;
        }
        else
        {
            cout << segmentTree[1].second + 1 << "\n";
        }
    }
    return 0;
}