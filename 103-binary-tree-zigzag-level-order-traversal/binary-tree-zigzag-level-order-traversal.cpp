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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> level;
        bool l2R = true;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==nullptr){
                if(l2R){
                    ans.push_back(level);
                    level.clear();
                }
                else{
                    reverse(level.begin(),level.end());
                    ans.push_back(level);
                    level.clear();
                }
                l2R = !l2R;
                if(q.empty()) break;
                else q.push(nullptr);
            }
            else{
                level.push_back(curr->val);
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
        }
        return ans;
    }
};