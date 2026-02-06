class Solution {
    private:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        bool isPal = true;
        while(start<=end){
            if(s[start]!=s[end]){
                isPal = false;
                break;
            }
            start++;
            end--;
        }
        return isPal;
    }

    void helper(int idx, string s, vector<string> list, vector<vector<string>> &ans){

        if(idx==s.size()){
            ans.push_back(list);
            return;
        }
        string str = "";
        for(int i=idx;i<s.size();i++){
            str += s[i];
            if(isPalindrome(str)){
                list.push_back(str);
                helper(i+1,s,list,ans);
                list.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> list;
        helper(0,s,list,ans);
        return ans;
    }
};