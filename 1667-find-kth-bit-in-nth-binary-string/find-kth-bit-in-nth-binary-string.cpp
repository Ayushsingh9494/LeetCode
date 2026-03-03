class Solution {
    private:
    string invert(string str){
        for(char &c: str){
            c = (c=='0')? '1':'0';
        }
        return str;
    }
public:
    char findKthBit(int n, int k) {
        if(k==1) return '0';
        string str = "0";
        int val = n;
        while(val!=1){
            string temp = invert(str);
            reverse(temp.begin(),temp.end());
            str += "1" + temp;
            val--;
        }
        return str[k-1];
    }
};