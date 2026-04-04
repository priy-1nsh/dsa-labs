#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool checkEqual(TreeNode* root1, TreeNode* root2) {
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;

    // we are going to do level traversal in both the trees to compare them -
    // which is same as the BFS - breadth first search

    // edge cases - if either one tree in Null or both trees are Null
    //  null tree means root==nullptr OR !root which means the same thing

    // (!root) === (root==nullptr)
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr && root2 != nullptr) return false;
    if (root1 != nullptr && root2 == nullptr) return false;
    q1.push(root1);
    q2.push(root2);

    // now, BFS
    while (!q1.empty() && !q2.empty()) {
        // while both are non-empty
        // run the loop
        TreeNode* node1 = q1.front();
        q1.pop();
        TreeNode* node2 = q2.front();
        q2.pop();

        if (node1->val != node2->val) return false;

        if (node1->left && node2->left) {
            q1.push(node1->left);
            q2.push(node2->left);
        } else if (node1->left || node2->left) {
            // only one of them has the left child
            return false;
        }

        if (node1->right && node2->right) {
            q1.push(node1->right);
            q2.push(node2->right);
        } else if (node1->right || node2->right) {
            return false;
        }
    }
    // if the loop ends, then it means all the levels are the same
    return true;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(4);

    // Expected: false

    bool ans = checkEqual(root1, root2);

    cout << boolalpha;
    cout << ans;

    return 0;
}