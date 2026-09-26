class Solution {
    private static long cal(int[] piles, int k){
        long cnt = 0;
        for(int i=0;i<piles.length;i++){
            cnt += (piles[i]+k-1)/k;
        }
        return cnt;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        if(h<n) return -1;
        Arrays.sort(piles);
        int s = 1;
        int e = piles[n-1];
        long ans = piles[n-1];
        while(s<=e){
            int mid = s + (e-s)/2;
            long num = cal(piles,mid);
            if(num<=h){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return (int)ans;
    }
}