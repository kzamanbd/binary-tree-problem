#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {50, 40, 45, 30, 35, 42, 32, 25, 20, 10};
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

    for (int val : v)
    {
        cout << val << " ";
    }

    return 0;
}