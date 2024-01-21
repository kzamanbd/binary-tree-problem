#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
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

void traversePaths(TreeNode* root, vector<int>& path, vector<vector<int>>& paths) {
    if (root == NULL) {
        return;
    }

    // Add the current node to the path
    path.push_back(root->val);

    // If the current node is a leaf node, add the path to the result
    if (root->left == NULL && root->right == NULL) {
        paths.push_back(path);
    }

    // Recursively traverse the left and right subtrees
    traversePaths(root->left, path, paths);
    traversePaths(root->right, path, paths);

    // Remove the current node from the path (backtrack)
    path.pop_back();
}

int main() {
    // Create a sample binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Traverse all paths in the binary tree
    vector<vector<int>> paths;
    vector<int> currentPath;
    traversePaths(root, currentPath, paths);

    // Print the result
    for (auto path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
