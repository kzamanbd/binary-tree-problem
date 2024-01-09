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

int countMaxHeight(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = countMaxHeight(root->left);
    int right = countMaxHeight(root->right);
    return max(left, right) + 1;
}

TreeNode *inputTreeLevelOrder(int &countNode)
{
    int n;
    cin >> n;
    TreeNode *root = new TreeNode(n);
    queue<TreeNode *> q;

    q.push(root);
    countNode++;

    while (!q.empty())
    {
        auto *it = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            countNode++;
            TreeNode *ln = new TreeNode(l);
            it->left = ln;
            if (it->left)
            {
                q.push(it->left);
            }
        }
        if (r != -1)
        {
            countNode++;
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

    int countNode = 0;
    TreeNode *root = inputTreeLevelOrder(countNode);

    int level = countMaxHeight(root);
    int res = pow(2, level) - 1;

    if (res == countNode)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}