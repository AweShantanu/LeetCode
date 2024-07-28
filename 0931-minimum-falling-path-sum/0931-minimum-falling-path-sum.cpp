class Solution {
public:
    // Main function to find the minimum falling path sum in the matrix
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = 1e9;

        // Initialize dp table with 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the first row of dp table
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int down = matrix[i][j] + dp[i - 1][j];
                int left = matrix[i][j] + ((j - 1 >= 0) ? dp[i - 1][j - 1] : 1e9);
                int right = matrix[i][j] + ((j + 1 < n) ? dp[i - 1][j + 1] : 1e9);
                dp[i][j] = min(down, min(left, right));
            }
        }

        // Find the minimum value in the last row of dp table
        for (int j = 0; j < n; ++j) {
            mini = min(mini, dp[m - 1][j]);
        }

        return mini;
    }
};
