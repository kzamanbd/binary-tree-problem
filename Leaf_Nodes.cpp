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

void leafNodes(TreeNode *root, vector<int> &nodes)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        nodes.push_back(root->val);
    }

    leafNodes(root->left, nodes);
    leafNodes(root->right, nodes);
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
    vector<int> nodes;
    leafNodes(root, nodes);
    sort(nodes.begin(), nodes.end(), greater<int>());
    for (int val : nodes)
    {
        cout << val << " ";
    }

    return 0;
}