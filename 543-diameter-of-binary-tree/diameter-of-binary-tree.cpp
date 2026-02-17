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
    int getHeight(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
public:
    int maxDiameter = 0; 
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int first = getHeight(root->left) + getHeight(root->right);
        int left =  diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        return max(first,max(left,right));
    }
};