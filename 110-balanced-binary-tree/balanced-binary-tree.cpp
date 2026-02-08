/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = helper(root->left);
        if (leftHeight == -1) return -1;  // left subtree already unbalanced

        int rightHeight = helper(root->right);
        if (rightHeight == -1) return -1; // right subtree already unbalanced

        if (abs(leftHeight - rightHeight) > 1) return -1; // current node unbalanced

        return 1 + max(leftHeight, rightHeight); // return height
    }

public:
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};
