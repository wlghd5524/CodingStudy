#include <iostream>
#include <vector>
#include <math.h>
#define MAX 100001
using namespace std;
int n, m;
int arr[MAX];
int makeMinSegmentTree(vector<pair<int, int>> &segmentTree, int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node].first = arr[start];
    }
    int mid = (start + end) / 2;
    return segmentTree[node].first = min(makeMinSegmentTree(segmentTree, node * 2, start, mid), makeMinSegmentTree(segmentTree, node * 2 + 1, mid + 1, end));
}
int makeMaxSegmentTree(vector<pair<int, int>> &segmentTree, int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node].second = arr[start];
    }
    int mid = (start + end) / 2;
    return segmentTree[node].second = max(makeMaxSegmentTree(segmentTree, node * 2, start, mid), makeMaxSegmentTree(segmentTree, node * 2 + 1, mid + 1, end));
}
int minResult(vector<pair<int, int>> &segmentTree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 2000000000;
    }
    if (left <= start && right >= end)
    {
        return segmentTree[node].first;
    }
    int mid = (start + end) / 2;
    return min(minResult(segmentTree, node * 2, start, mid, left, right), minResult(segmentTree, node * 2 + 1, mid + 1, end, left, right));
}
int maxResult(vector<pair<int, int>> &segmentTree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && right >= end)
    {
        return segmentTree[node].second;
    }
    int mid = (start + end) / 2;
    return max(maxResult(segmentTree, node * 2, start, mid, left, right), maxResult(segmentTree, node * 2 + 1, mid + 1, end, left, right));
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    vector<pair<int, int>> segmentTree(treeSize);
    makeMinSegmentTree(segmentTree, 1, 0, n - 1);
    makeMaxSegmentTree(segmentTree, 1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << minResult(segmentTree, 1, 0, n - 1, a - 1, b - 1) << " " << maxResult(segmentTree, 1, 0, n - 1, a - 1, b - 1) << "\n";
    }
    return 0;
}