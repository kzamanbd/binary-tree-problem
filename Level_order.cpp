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

void levelOrder(TreeNode *root)
{
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

    TreeNode *root = new TreeNode(10);
    TreeNode *a = new TreeNode(20);
    TreeNode *b = new TreeNode(30);
    TreeNode *c = new TreeNode(40);
    TreeNode *d = new TreeNode(50);
    TreeNode *e = new TreeNode(60);
    TreeNode *f = new TreeNode(70);
    TreeNode *g = new TreeNode(80);
    TreeNode *h = new TreeNode(90);
    TreeNode *i = new TreeNode(100);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    b->right = d;
    d->left = f;
    d->right = g;
    h->right = i;

    levelOrder(root);

    return 0;
}