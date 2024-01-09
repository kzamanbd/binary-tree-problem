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

void maxAndMinLeafNode(TreeNode *root, int &mx, int &mn)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        mx = max(mx, root->val);
        mn = min(mn, root->val);
    }
    maxAndMinLeafNode(root->left, mx, mn);
    maxAndMinLeafNode(root->right, mx, mn);
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
    int mx = INT_MIN, mn = INT_MAX;
    maxAndMinLeafNode(root, mx, mn);
    cout << mx << " " << mn;

    return 0;
}