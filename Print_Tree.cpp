#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> reverseLevelOrder(TreeNode *root)
{
    // Write your code here.
    if (root == NULL)
    {
        return {};
    }
    queue<TreeNode *> q;
    vector<int> res;
    q.push(root);

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        res.push_back(it->val);
        if (it->right)
        {
            q.push(it->right);
        }
        if (it->left)
        {
            q.push(it->left);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

TreeNode *inputTreeLevelOrder()
{
    int n;
    cin >> n;
    TreeNode *root = new TreeNode(n);
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        auto *it = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            TreeNode *ln = new TreeNode(l);
            it->left = ln;
            if (it->left)
            {
                q.push(it->left);
            }
        }
        if (r != -1)
        {
            TreeNode *rn = new TreeNode(r);
            it->right = rn;
            if (it->right)
            {
                q.push(it->right);
            }
        }
    }
    return root;
}

int main()
{
    TreeNode *root = inputTreeLevelOrder();

    vector<int> vec = reverseLevelOrder(root);

    for (int val : vec)
    {
        cout << val << " ";
    }

    return 0;
}