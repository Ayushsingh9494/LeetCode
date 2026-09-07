class Solution {
    private boolean helper(String s){
        int n = s.length();
        int l = 0;
        int r = n-1;
        while(l<=r){
            if(s.charAt(l)!=s.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    public boolean validPalindrome(String s) {
        int n = s.length();
        int cnt = 0;
        int l = 0;
        int r = n-1;

        while(l<=r){
            if(s.charAt(l) != s.charAt(r)){
                if(cnt==0){
                    if (helper(s.substring(l+1,r+1))) l++;
                    else if(helper(s.substring(l,r))) r--;
                    cnt++;
                    continue;
                    
                }
                else return false;
            }
            l++;
            r--;
        }
        return true;
    }
}