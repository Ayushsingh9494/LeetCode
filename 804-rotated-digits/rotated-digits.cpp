class Solution {
    bool containsDigit(int num, int digit) {
    if (digit < 0 || digit > 9) return false;
    num = std::abs(num);  // Handle negatives
    do {
        if (num % 10 == digit) return true;
        num /= 10;
    } while (num > 0);
    return false;
    }

    private: bool isValid(int x){
        int rotated[] = {0,1,5,-1,-1,2,9,-1,8,6};
        vector<int> digits;
        int copy = x;
        while(copy!=0){
            digits.push_back(copy%10);
            copy/=10;
        }
        for(int i : digits){
            if(rotated[i]==-1) return false;
        }
        return true;
    }
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i=2;i<=n;i++){
            if(isValid(i) && (containsDigit(i,2) || containsDigit(i,5) || containsDigit(i,6) || containsDigit(i,9))){
                cnt += 1;
            }
        }
        return cnt;
    }
};