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

void getLeftMostNode(TreeNode *root, vector<int> &left)
{
    if (root == NULL)
    {
        return;
    }
    left.push_back(root->val);
    if (root->left)
    {
        getLeftMostNode(root->left, left);
    }
    else if (root->right)
    {
        getLeftMostNode(root->right, left);
    }
}
void getRightMostNode(TreeNode *root, vector<int> &right)
{
    if (root == NULL)
    {
        return;
    }
    right.push_back(root->val);

    if (root->right)
    {
        getRightMostNode(root->right, right);
    }
    else if (root->left)
    {
        getRightMostNode(root->left, right);
    }
}

int main()
{
    TreeNode *root = inputTreeLevelOrder();

    vector<int> left, right;
    getLeftMostNode(root->left, left);
    getRightMostNode(root->right, right);

    reverse(left.begin(), left.end());

    for (int val : left)
    {
        cout << val << " ";
    }
    cout << root->val << " ";

    for (int val : right)
    {
        cout << val << " ";
    }

    return 0;
}