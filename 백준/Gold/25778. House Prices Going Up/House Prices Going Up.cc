#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<long long int> segmentTree;
long long int arr[500000];
long long int makeSegmentTree(int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = makeSegmentTree(node * 2, start, mid) + makeSegmentTree(node * 2 + 1, mid + 1, end);
}
long long int update(int node, int start, int end, int index, int value)
{
    if (index < start || index > end)
    {
        return segmentTree[node];
    }
    if (start == end)
    {
        return segmentTree[node] += value;
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = update(node * 2, start, mid, index, value) + update(node * 2 + 1, mid + 1, end, index, value);
}
long long int sum(int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (start >= left && right >= end)
    {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    segmentTree.resize(treeSize);
    makeSegmentTree(1, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        if (cmd == 'R')
        {
            cout << sum(1, 0, n - 1, a - 1, b - 1) << "\n";
        }
        else
        {
            update(1, 0, n - 1, a - 1, b);
            arr[a - 1] += b;
        }
    }
}