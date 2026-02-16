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
    void helper(TreeNode* p, TreeNode* q,bool &check){
        if(p==nullptr && q==nullptr){
            return;
        } 
        else if((p==nullptr && q!=nullptr) || (q==nullptr && p!=nullptr) || p->val!=q->val){
            check = false;
        }
        else{
            helper(p->left,q->left,check);
            helper(p->right,q->right,check);
        }
        return;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame = true;
        helper(p,q,isSame);
        return isSame;
    }
};