class Solution {
public:
    // Recursive function to find the minimum path sum
    // Parameters: grid - input grid, m - current row, n - current column, dp - memoization table
    int sol(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        // Base case: if we reach the starting cell
        if (m == 0 && n == 0) {
            return grid[m][n];
        }

        // If out of bounds, return a large value (infinity equivalent)
        if (m < 0 || n < 0) {
            return INT_MAX;
        }

        // If the value is already computed, return it
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        // Compute the minimum path sum from the cell above and to the left
        int up = sol(grid, m - 1, n, dp);
        int left = sol(grid, m, n - 1, dp);

        // Store the result in dp table and return it
        return dp[m][n] = grid[m][n] + min(up, left);
    }

    // Main function to find the minimum path sum in m x n grid
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize dp table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Call the recursive function starting from bottom-right corner
        return sol(grid, m - 1, n - 1, dp);
    }
};
