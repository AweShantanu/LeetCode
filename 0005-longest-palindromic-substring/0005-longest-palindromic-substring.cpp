// class Solution {
// public:
//     bool isPalindrome(string&s,int start,int end)
//         {
//             while(start<  end)
//             {
//                 if(s[start]!=s[end])
//                 {
//                     return false;
//                 }
//                 start++;
//                 end--;
//             }
//             return true;
//         }
//     string longestPalindrome(string s) {
//         string ans = "";
        
//         for(int i=0;i<s.length();i++)
//         {
//             for(int j=0; j<s.size();j++)
//             {
//                 if(isPalindrome(s,i,j)){
//                     string t=s.substr(i,j-i+1);
//                     ans=t.length()>ans.size() ? t:ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s; // If the input string is empty or has only one character, it's a palindrome
        
        int start = 0; // Start index of the longest palindrome substring found so far
        int maxLength = 1; // Length of the longest palindrome substring found so far
        
        // Dynamic programming table to store whether substrings are palindromes or not
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        // Check for substrings of length 3 or more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1; // Ending index of the current substring
                
                // Check if the current substring is a palindrome and the characters at the ends match
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength); // Extract the longest palindrome substring
    }
};
