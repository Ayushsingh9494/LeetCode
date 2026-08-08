class Solution {
    private:
    int beauty(unordered_map<char,int> &m1){
        int maxFreq = 0;
        int minFreq = 501;
        for(auto &p : m1){
            maxFreq = max(maxFreq,p.second);
            minFreq = min(minFreq,p.second);
        }
        return maxFreq-minFreq;
    }
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        unordered_map<char,int> m1;
        int l = 0;
        int r = 0;
        for(int i=0;i<n-1;i++){
            m1.clear();
            m1[s[i]]++;
            for(int j=i+1;j<n;j++){
                m1[s[j]]++;
                sum += beauty(m1);
            }
        }
        return sum;
    }

};