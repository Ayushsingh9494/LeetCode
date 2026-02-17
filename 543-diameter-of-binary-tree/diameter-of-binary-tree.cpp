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
    int diameter = 0;
    int getHeight(TreeNode* root){
        if(root==nullptr) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int curr = left+right;
        diameter = max(curr,diameter);
        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return diameter;
    }
};