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

void countNodesLevel(TreeNode *root)
{
    int count = 0;
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        auto *f = q.front();
        q.pop();
        count++;
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
    cout << count;
}

int countNodePostorder(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = countNodePostorder(root->left);
    int right = countNodePostorder(root->right);
    return left + right + 1;
}

int main()
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

    cout << countNodePostorder(root);

    return 0;
}