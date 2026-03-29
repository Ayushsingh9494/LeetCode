class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        string c1 = s1;
        char temp = c1[2];
        c1[2] = c1[0];
        c1[0] = temp;
        
        string c2 = s1;
        temp = c2[3];
        c2[3] = c2[1];
        c2[1] = temp;

        string c3 = s1;
        temp = c3[2];
        c3[2] = c3[0];
        c3[0] = temp;
        temp = c3[3];
        c3[3] = c3[1];
        c3[1] = temp;
        if(s2==c1 || s2==c2 || s2==c3) return true;
        return false;
    }
};