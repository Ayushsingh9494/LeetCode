class Solution {
    public String reverseVowels(String s) {
        int n = s.length();
        String vowelSet = "aeiouAEIOU";
        char[] str = s.toCharArray();
        int l = 0;
        int r = n-1;
        while(l<r){
            while(l<r && vowelSet.indexOf(str[l])==-1){l++;}
            while(l<r && vowelSet.indexOf(str[r])==-1){r--;}
            if(vowelSet.contains("" + s.charAt(l)) && vowelSet.contains("" + s.charAt(r))){
                char temp = str[l];
                str[l] = str[r];
                str[r] = temp;
            }
            l++;
            r--;
        }
        return new String(str);
    }
}