class Solution {
public:
    bool judgeCircle(string moves) {
        int u=0;
        int d=0;
        int l=0;
        int r=0;
        for(char c: moves){
            if(c=='U') u++;
            else if(c=='D') d++;
            else if(c=='L') l++;
            else r++;
        }
        cout << u << d << l << r;
        return (u==d && r==l);
    }
};