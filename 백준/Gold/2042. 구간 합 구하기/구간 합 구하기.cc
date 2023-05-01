#include <iostream>
#include <vector>
#include <math.h>
#define MAX 1000001
using namespace std;
int n, m, k;
long long int arr[MAX];
long long makeSegmentTree(vector<long long> &segmentTree, int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = makeSegmentTree(segmentTree, node * 2, start, mid) + makeSegmentTree(segmentTree, node * 2 + 1, mid + 1, end);
}
void update(vector<long long> &segmentTree, int node, int start, int end, int index, long long value)
{
    if (index < start || index > end)
    {
        return;
    }
    segmentTree[node] += value;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(segmentTree, node * 2, start, mid, index, value);
        update(segmentTree, node * 2 + 1, mid + 1, end, index, value);
    }
}
long long sum(vector<long long> &segmentTree, int node, int left, int right, int start, int end)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && right >= end)
    {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    return sum(segmentTree, node * 2, left, right, start, mid) + sum(segmentTree, node * 2 + 1, left, right, mid + 1, end);
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    vector<long long int> segmentTree(treeSize);
    makeSegmentTree(segmentTree, 1, 0, n - 1);
    for (int i = 0; i < m + k; i++)
    {
        long long int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1)
        {
            update(segmentTree, 1, 0, n - 1, a - 1, b - arr[a - 1]);
            arr[a - 1] = b;
        }
        else
        {
            cout << sum(segmentTree, 1, a - 1, b - 1, 0, n - 1) << "\n";
        }
    }
}