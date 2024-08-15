class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int maxi = 0;
        for (auto &it : s) {
            if (it == '(') {
                open++;
                maxi = max(maxi, open);  // Update max depth when we go deeper
            } else if (it == ')') {
                open--;
            }
        }
        return maxi;
    }
};
