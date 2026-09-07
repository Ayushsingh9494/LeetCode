class Solution {
    public int mySqrt(int x) {
        if(x==0 || x==1) return x;
        long l = 1;
        long h = x;
        while(l<=h){
            long mid = l+(h-l)/2;
            long sq = mid*mid;
            if(sq==x){
                return (int)mid;
            }
            else if(sq>x){
                h = mid-1;
            }
            else l = mid+1;
        }
        return (int)h;
    }
}