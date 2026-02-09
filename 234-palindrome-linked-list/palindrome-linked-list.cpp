/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp!=nullptr){
            st.push(temp);
            temp = temp->next;
        }
        temp = head;
        while(temp!=nullptr){
            ListNode* stackNode = st.top();
            st.pop();
            if(temp->val!=stackNode->val) return false;
            temp = temp->next;
        }
        return true;
    }
};