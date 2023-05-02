#include <iostream>
#include <vector>
#include <math.h>
#define MAX 100000
using namespace std;
int n, q;
long long int arr[MAX];
vector<long long int> segmentTree;
long long int makeSegmentTree(int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = makeSegmentTree(node * 2, start, mid) + makeSegmentTree(node * 2 + 1, mid + 1, end);
}
void update(int node, int start, int end, int index, long long int value)
{
    if (index < start || index > end)
    {
        return;
    }
    segmentTree[node] += value;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, value);
        update(node * 2 + 1, mid + 1, end, index, value);
    }
}
long long int sum(int node, int start, int end, int left, int right)
{
    if (end < left || start > right)
    {
        return 0;
    }
    if (start >= left && end <= right)
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
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    segmentTree.resize(treeSize);
    makeSegmentTree(1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y)
        {
            int tmp = x;
            x = y;
            y = tmp;
        }
        cout << sum(1, 0, n - 1, x - 1, y - 1) << "\n";
        update(1, 0, n - 1, a - 1, b - arr[a - 1]);
        arr[a - 1] = b;
    }
}