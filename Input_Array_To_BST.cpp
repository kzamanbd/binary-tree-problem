#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* convertBST(vector<int> arr, int l, int r) {
    if (l > r) {
        return NULL;
    }
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    TreeNode* leftNode = convertBST(arr, l, mid - 1);
    TreeNode* rightNode = convertBST(arr, mid + 1, r);
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

void levelOrderPrint(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
        auto* f = q.front();
        q.pop();
        cout << f->val << " ";
        if (f->left) {
            q.push(f->left);
        }
        if (f->right) {
            q.push(f->right);
        }
    }
}

void preorder(TreeNode* root) {
    if (!root) {
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void inOrder(TreeNode* root) {
    if (!root) {
        return;
    }

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << "Array: ";
    for (auto val : arr) {
        cout << val << " ";
    }
    cout << endl;
    TreeNode* root = convertBST(arr, 0, n - 1);
    cout << "Level Order: ";
    levelOrderPrint(root);
    cout << endl << "Preorder: ";
    preorder(root);
    cout << endl << "Postorder: ";
    postorder(root);
    cout << endl << "In order: ";
    inOrder(root);

    return 0;
}