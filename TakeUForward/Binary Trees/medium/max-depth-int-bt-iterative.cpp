#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    int level = 0;
    if (root == nullptr) return 0;

    queue<TreeNode*> q;
    q.push(root);

    TreeNode* node = root;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* front = q.front();
            q.pop();

            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        level++;
    }
    return level;
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