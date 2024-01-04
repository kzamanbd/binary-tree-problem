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

vector<int> getLevelOrder(TreeNode *root, int lvl)
{
    queue<pair<TreeNode *, int>> q;
    vector<int> res;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        TreeNode *node = it.first;
        int level = it.second;

        if (level == lvl)
        {
            res.push_back(node->val);
        }

        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }

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
    int level;
    cin >> level;
    vector<int> vec = getLevelOrder(root, level);
    if (vec.size() == 0)
    {
        cout << "Invalid";
    }
    else
    {
        for (int val : vec)
        {
            cout << val << " ";
        }
    }

    return 0;
}