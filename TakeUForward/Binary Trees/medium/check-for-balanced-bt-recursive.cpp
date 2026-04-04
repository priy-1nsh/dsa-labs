#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// getHeight function
// using level order traversal
int getHeight(TreeNode* root) {
    if (root == nullptr) return 0;

    int level = 0;
    queue<TreeNode*> q;
    q.push(root);

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

bool balancedOrNot(TreeNode* root) {
    // base case
    // if the tree is empty, then balanced
    if (root == nullptr) return true;
    // if the left has 1 node, right has one node, OR the left has 1 node and
    // the right has 0 nodes OR vice versa

    int lh = getHeight(root->left);   //  height of left subtree
    int rh = getHeight(root->right);  // height of the right subtree

    return (abs(lh - rh) <= 1) && balancedOrNot(root->left) &&
           balancedOrNot(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);

    bool ans = balancedOrNot(root);

    cout << boolalpha;
    cout << ans << endl;

    return 0;
}

// TC - O(N2)