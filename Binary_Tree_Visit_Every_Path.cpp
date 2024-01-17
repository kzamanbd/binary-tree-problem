#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

void traversePaths(TreeNode* root, vector<int>& currentPath, vector<vector<int>>& allPaths) {
    if (root == NULL) {
        return;
    }

    // Add the current node to the path
    currentPath.push_back(root->value);

    // If the current node is a leaf node, add the path to the result
    if (root->left == NULL && root->right == NULL) {
        allPaths.push_back(currentPath);
    }

    // Recursively traverse the left and right subtrees
    traversePaths(root->left, currentPath, allPaths);
    traversePaths(root->right, currentPath, allPaths);

    // Remove the current node from the path (backtrack)
    currentPath.pop_back();
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
    for (const auto& path : paths) {
        for (int nodeValue : path) {
            cout << nodeValue << " ";
        }
        cout << "\n";
    }

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
