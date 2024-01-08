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

int sumWithoutLeaf(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    int l = sumWithoutLeaf(root->left);
    int r = sumWithoutLeaf(root->right);
    return l + r + root->val;
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

    cout << sumWithoutLeaf(root);

    return 0;
}