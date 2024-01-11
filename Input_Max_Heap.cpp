#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);

        int cIdx = v.size() - 1;
        while (cIdx != 0)
        {
            int pIdx = (cIdx - 1) / 2;
            if (v[cIdx] > v[pIdx])
            {
                swap(v[cIdx], v[pIdx]);
            }
            else
            {
                break;
            }
            cIdx = pIdx;
        }
    }

    for (int val : v)
    {
        cout << val << " ";
    }

    return 0;
}