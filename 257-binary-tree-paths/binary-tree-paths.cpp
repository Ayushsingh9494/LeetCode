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
    void helper(TreeNode* root, vector<string> &paths,string s){
        if(root==nullptr) return;
        int len = s.size();
        if(s.size()==0){
            s += to_string(root->val);
        }
        else{
            s += "->" + to_string(root->val); 
        }

        if(root->left==nullptr && root->right==nullptr){
            paths.push_back(s);
        }
        helper(root->left,paths,s);
        helper(root->right,paths,s);

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path = "";
        helper(root,paths,path);
        return paths;
    }
};