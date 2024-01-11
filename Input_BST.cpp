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

void insertNode(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    if (root->val > val)
    {
        if (!root->left)
        {
            root->left = new TreeNode(val);
        }
        else
        {
            insertNode(root->left, val);
        }
    }
    else
    {
        if (!root->right)
        {
            root->right = new TreeNode(val);
        }
        else
        {
            insertNode(root->right, val);
        }
    }
}

void levelOrderPrint(TreeNode *root)
{
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
        cout << f->val << " ";
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
}

int main()
{
    TreeNode *root = inputTreeLevelOrder();
    int val;
    cin >> val;
    insertNode(root, val);
    levelOrderPrint(root);
    return 0;
}