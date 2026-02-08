struct Node{
    int val;
    Node* prev;
    Node* next;

    Node(int val){
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }

    Node(int val,Node* prev,Node* next){
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

class Solution {
    private:
    bool isSorted(Node* head){
        Node* temp = head;
        while(temp->next!=nullptr){
            if(temp->val>temp->next->val) return false;
            temp = temp->next;
        }
        return true;
    }

    int getSize(Node* head){
        Node* temp = head;
        int size = 0;
        while(temp!=nullptr){
            temp = temp->next;
            size++;
        }
        return size;
    }

    int helper(vector<int> &nums){
        int n = nums.size();
        int steps = 0;
        Node* head = new Node(nums[0]);
        Node* prev = head;
        for(int i=1;i<n;i++){
            Node* temp = new Node(nums[i],prev,nullptr);
            prev->next = temp;
            prev = temp;
        }
        while(!isSorted(head)){
            Node* bestNode = head;
            Node* temp = head; 
            int minSum = INT_MAX;
            while(temp->next!=nullptr){
                int adjSum = temp->val + temp->next->val;
                if(adjSum<minSum){
                    minSum = adjSum;
                    bestNode = temp;
                }
                temp=temp->next;
            }
            steps++;
            bestNode->val = minSum;
            Node* removable = bestNode->next;
            bestNode->next = removable->next;
            if(removable->next!=nullptr){
                removable->next->prev = bestNode;
            }
            delete removable;
        }
        return steps;
    }
    public:
    int minimumPairRemoval(vector<int>& nums) {
        return helper(nums);
    }
};















// private:
//     bool isSorted(vector<int> &nums){
//         int n = nums.size();
//         bool flag = true;
//         for(int i=0;i<n-1;i++){
//             if(nums[i]>nums[i+1]){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag) return true;
//         return false;
//     }
// public:
//     int minimumPairRemoval(vector<int>& nums) {
//         int steps = 0;
//         while(nums.size()>1){
//             if(isSorted(nums)) break;
//             int idx = -1;
//             int minSum = INT_MAX;
//             for(int i=0;i<nums.size()-1;i++){
//                 int adjSum = nums[i]+nums[i+1];
//                 if(adjSum<minSum){
//                     minSum = adjSum;
//                     idx = i;
//                 }
//             }
//             steps++; 
//             nums[idx] = minSum;
//             nums.erase(nums.begin()+idx+1);
//          }
//         return steps;
//     }