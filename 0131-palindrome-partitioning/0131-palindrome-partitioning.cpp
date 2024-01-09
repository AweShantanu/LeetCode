class Solution {
public:
    int n;
    vector<vector<string>> result;
    
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void solve(string &s, int idx, vector<string> &temp, vector<vector<string>> &result) {
        if (idx == n) {
            result.push_back(temp);
            return;
        }
        
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, temp, result);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        n = s.length();
        
        solve(s, 0, temp, result);
        return result;
    }
};
