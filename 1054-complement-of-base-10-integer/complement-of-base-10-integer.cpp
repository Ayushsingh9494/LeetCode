class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int bit_len = 32 - __builtin_clz(n);
        int mask = (1<<(bit_len))-1;
        return n^mask;
    }
};