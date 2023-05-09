#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int arr[1000000];
vector<int> segmentTree;
int makeSegmentTree(int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = max(makeSegmentTree(node * 2, start, mid), makeSegmentTree(node * 2 + 1, mid + 1, end));
}
int result(int node, int start, int end, int left, int right)
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
    return max(result(node * 2, start, mid, left, right), result(node * 2 + 1, mid + 1, end, left, right));
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    segmentTree.resize(treeSize);
    makeSegmentTree(1, 0, n - 1);
    for (int i = m - 1; i < n - m + 1; i++)
    {
        cout << result(1, 0, n - 1, i - (m - 1), i + (m - 1)) << " ";
    }
}