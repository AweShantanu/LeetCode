class Solution {
public:
    
    // Recursive function to find unique paths
    // Parameters: m - current row, n - current column, dp - memoization table
    int sol(int m, int n, vector<vector<int>>& dp) {
        // Base case: if we reach the starting cell
        if (m == 0 && n == 0) {
            return 1;
        }

        // If out of bounds, return 0
        if (m < 0 || n < 0) {
            return 0;
        }
        
        // If the value is already computed, return it
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        
        // Compute the number of paths from the cell above
        int up = sol(m - 1, n, dp);
        
        // Compute the number of paths from the cell to the left
        int left = sol(m, n - 1, dp);
        
        // Store the result in dp table and return it
        return dp[m][n] = up + left;
    }

    // Main function to find unique paths in m x n grid
    int uniquePaths(int m, int n) {
        // Initialize dp table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Call the recursive function starting from bottom-right corner
        return sol(m - 1, n - 1, dp);
    }
};
