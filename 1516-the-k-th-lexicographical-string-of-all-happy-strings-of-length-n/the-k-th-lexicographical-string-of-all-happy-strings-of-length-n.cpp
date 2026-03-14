class Solution {
    private:
    void generateStrings(int n, int k, int &cnt, string &curr, string &result){
        if(curr.size()==n){
            if(++cnt==k) result = curr;
            return;
        }

        for(char c ='a';c <= 'c';c++){
            if(curr.size()>0 && c==curr.back()) continue;
            curr.push_back(c);
            generateStrings(n,k,cnt,curr,result);
            if(result != "") return;
            curr.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        int total = 3*(1<<(n-1));
        if(k>total) return "";
        string result = "";
        string curr = "";
        int cnt = 0;
        generateStrings(n,k,cnt,curr,result);
        return result;
    }
};