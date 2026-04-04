#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    // base case
    if (root == nullptr) return 0;

    // recursion
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    // work
    return 1 + max(lh, rh);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int ans = maxDepth(root);

    cout << ans << endl;

    return 0;
}