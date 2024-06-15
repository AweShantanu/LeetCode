#include <string>
#include <algorithm>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int n = s.size();
        string res = "";

        // First pass: remove unmatched closing brackets
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
                res.push_back(s[i]);
            } else if (s[i] == ')') {
                if (open > 0) {
                    open--;
                    res.push_back(s[i]);
                }
            } else {
                res.push_back(s[i]);
            }
        }

        // Second pass: remove unmatched opening brackets from the end
        string result = "";
        int m = res.size();
        for (int i = m - 1; i >= 0; i--) {
            if (res[i] == '(' && open > 0) {
                open--;
            } else {
                result.push_back(res[i]);
            }
        }

        // Reverse the result to restore the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};
