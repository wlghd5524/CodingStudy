#include <iostream>
#include <vector>
#include <math.h>
#define MAX 1000000
#define MOD 1000000007
using namespace std;
int n, m, k;
int arr[MAX];
vector<long long int> segmentTree;
long long int makeSegmentTree(int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = (makeSegmentTree(node * 2, start, mid) * makeSegmentTree(node * 2 + 1, mid + 1, end)) % MOD;
}
void update(int node, int start, int end, int index, long long int value)
{
    if (index < start || index > end)
    {
        return;
    }

    if (start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, value);
        update(node * 2 + 1, mid + 1, end, index, value);
        segmentTree[node] = (segmentTree[node * 2] * segmentTree[node * 2 + 1]) % MOD;
    }
    else
    {
        segmentTree[node] = value;
        return;
    }
}
long long int multi(int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
    {
        return 1;
    }
    if (start >= left && end <= right)
    {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    return (multi(node * 2, start, mid, left, right) * multi(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    segmentTree.resize(treeSize);
    makeSegmentTree(1, 0, n - 1);
    for (int i = 0; i < m + k; i++)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1)
        {
            update(1, 0, n - 1, a - 1, b);
            arr[a - 1] = b;
        }
        else
        {
            cout << multi(1, 0, n - 1, a - 1, b - 1) << "\n";
        }
    }
    return 0;
}