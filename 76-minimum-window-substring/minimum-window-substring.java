class Solution {
    public String minWindow(String s, String t) {
        int[] need = new int[128];
        int[] window = new int[128];
        for(char c: t.toCharArray()){
            need[c]++;
        }

        int required = t.length();
        int formed = 0;

        int l = 0;
        int r = 0;

        int minLen = Integer.MAX_VALUE;
        int start = 0;

        while(r < s.length()){
            char c = s.charAt(r);
            window[c]++;
            if(need[c] > 0 && window[c]<=need[c]){
                formed++;
            }

            while(formed==required){
                int currLen = r - l + 1;
                if(currLen < minLen){
                    minLen = currLen;
                    start = l;
                }
                char cl = s.charAt(l);
                if(need[cl] > 0 && window[cl]==need[cl]){
                    formed--;
                }
                window[cl]--;
                l++;
            }
            r++;
        }
        if(minLen==Integer.MAX_VALUE) return "";
        return s.substring(start,start+minLen);
    }
}