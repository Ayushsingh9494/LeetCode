class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int prevDistance = 0;
        int nextDistance = 0;
        bool found = false;
        for(int i=startIndex;i<2*n;i++){
            if(words[i%n]==target){
                found = true;
                break;
            }
            nextDistance++;
        }
        for(int i=n+startIndex;i>=0;i--){
            if(words[i%n]==target){
                found = true;
                break;
            }
            prevDistance++;
        }

        if(!found) return -1;
        return min(prevDistance,nextDistance);
    }
};