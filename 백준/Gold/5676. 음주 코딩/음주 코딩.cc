#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
vector<int> segmentTree;
int arr[100000];
int check(int a)
{
    if (a > 0)
    {
        return 1;
    }
    if (a < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int makeSegmentTree(int node, int start, int end)
{
    if (start == end)
    {
        return segmentTree[node] = check(arr[start]);
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = check(makeSegmentTree(node * 2, start, mid)) * check(makeSegmentTree(node * 2 + 1, mid + 1, end));
}
int update(int node, int start, int end, int index, int value)
{
    if (start > index || end < index)
    {
        return segmentTree[node];
    }
    if (start == end)
    {
        return segmentTree[node] = check(value);
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = check(update(node * 2, start, mid, index, value)) * check(update(node * 2 + 1, mid + 1, end, index, value));
}
int multi(int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
    {
        return 1;
    }
    if (start >= left && right >= end)
    {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    return check(multi(node * 2, start, mid, left, right)) * check(multi(node * 2 + 1, mid + 1, end, left, right));
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    while (cin >> n >> k)
    {
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int treeDepth = ceil(log2(n));
        int treeSize = 1 << (treeDepth + 1);
        segmentTree.clear();
        segmentTree.resize(treeSize);
        makeSegmentTree(1, 0, n - 1);
        for (int i = 0; i < k; i++)
        {
            char cmd;
            int a, b;
            cin >> cmd >> a >> b;
            if (cmd == 'C')
            {
                update(1, 0, n - 1, a - 1, b);
                arr[a - 1] = b;
            }
            else
            {
                int result = multi(1, 0, n - 1, a - 1, b - 1);
                if (result < 0)
                {
                    cout << "-";
                }
                else if (result > 0)
                {
                    cout << "+";
                }
                else
                {
                    cout << 0;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}