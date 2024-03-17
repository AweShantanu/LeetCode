#include <string>
#include <cctype>

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        int n = s.length();
        
        // Calculate the size of the decoded string
        for (char& ch : s) {
            if (isalpha(ch)) {
                size++;
            } else {
                size *= (ch - '0');
            }
        }
        
        // Iterate backward to find the character at index k
        for (int i = n - 1; i >= 0; i--) {
            k %= size; // Adjust k based on the current size
            
            // Check if k points to a character in the decoded string
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            
            // Update the size based on the current character
            if (isdigit(s[i])) {
                size /= (s[i] - '0');
            } else {
                size--;
            }
        }
        
        return ""; // Return empty string if k is out of range
    }
};
