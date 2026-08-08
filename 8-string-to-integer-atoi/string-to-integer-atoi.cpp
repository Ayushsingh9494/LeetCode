#include <iostream>
#include <string>
using namespace std;

class Solution {
    private:
    int build(string &s, int i, long long num,int sign){
        if(i>=s.size() || !isdigit(s[i])){
            return num*sign;
        }
        num = num*10 + s[i]-'0';
        if(sign == 1 && num > INT_MAX){
            return INT_MAX;
        }
        if(sign == -1 && -num < INT_MIN){
            return INT_MIN;
        }

        return build(s,i+1,num,sign);
    }
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        int sign = 1;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign = -1;
            i++;
        }
        return build(s,i,0,sign);
    }
};


























// class Solution {
// public:
//     int myAtoi(string s) {
//         int i = 0, sign = 1;
//         long res = 0; // Using long to handle overflow cases

//         // Trim leading spaces
//         while (i < s.size() && s[i] == ' ') i++;
//         if (i == s.size()) return 0;

//         // Check for sign
//         if (s[i] == '-') { sign = -1; i++; }
//         else if (s[i] == '+') i++;

//         // Process numerical characters
//         while (i < s.size() && isdigit(s[i])) {
//             res = res * 10 + (s[i] - '0');

//             // Handle overflow
//             if (sign * res > INT_MAX) return INT_MAX;
//             if (sign * res < INT_MIN) return INT_MIN;

//             i++;
//         }

//         return (int)(sign * res);
//     }
// };
// class Solution {
//     private:
//     string trim(string s) {
//         int start = 0;
//         int end = s.size() - 1;

//         while (start < s.size() && isspace(s[start])) start++;
//         while (end >= start && isspace(s[end])) end--;

//         return s.substr(start, end - start + 1);
//     }
// public:
//     int myAtoi(string s) {
//         bool isNegative = false;
//         s = trim(s);
//         if(!isdigit(s[0]) && s[0]!='+' && s[0]!='-'){
//             return 0;
//         }
//         if(s[0]=='-'){
//             isNegative = true;
//             s = s.substr(1);
//         }

//         if(isNegative && !isdigit(s[0])) return 0;
//         if(s[0]=='+'){
//             s = s.substr(1);
//         }

//         int n = s.size();
//         long res = 0;
//         for(int i=0;i<n;i++){
//             if(!isdigit(s[i])) break;
//             res = res*10 + s[i]-'0';
//             cout << res << endl;
//             if(res>INT_MAX){
//                 return (isNegative)? INT_MIN : INT_MAX;
//             }
//         }
//         return (isNegative)? (int)(-1*res) : (int)res;
//     }
// };