class Solution {
    private:
    string trim(string s) {
    int start = 0;
    while (start < s.size() && isspace(s[start])) start++;

    int end = s.size() - 1;
    while (end >= 0 && isspace(s[end])) end--;

    return s.substr(start, end - start + 1);
}
public:
    string reverseWords(string s) {
        // string res = "";
        // stringstream ss(s);
        // string word;
        // vector<string> words;

        // while(ss >> word){
        //     words.push_back(word);
        // }
        // reverse(words.begin(),words.end());
        // for(string w: words){
        //     res += w + " ";
        // }
        // if(!res.empty()) res.pop_back();
        // return res;
        s = trim(s);
        string s1 = "";
        string res = "";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                reverse(s1.begin(),s1.end());
                if(s1!=""){
                res += s1 + " ";
                s1 = "";
                }
            }
            else{
                if(s[i]!=' ') s1 += s[i];
            }
        }
        reverse(s1.begin(),s1.end());
        res += s1;
        return res;
            
    }
};