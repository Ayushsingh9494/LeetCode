class Solution {
public:
    int reverseBits(int n) {
        string binary = bitset<32>(n).to_string();
        reverse(binary.begin(),binary.end());
        int back = stoi(binary,nullptr,2);
        return back;
    }
};