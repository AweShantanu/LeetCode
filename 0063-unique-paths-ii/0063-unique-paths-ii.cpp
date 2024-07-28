class Solution {
public:
    // Recursive function to find unique paths
    // Parameters: obs - obstacle grid, m - current row, n - current column, dp - memoization table
    int sol(vector<vector<int>>& obs, int m, int n, vector<vector<int>>& dp) {
        // If out of bounds or there is an obstacle, return 0
        if (m < 0 || n < 0 || obs[m][n] == 1) {
            return 0;
        }

        // Base case: if we reach the starting cell
        if (m == 0 && n == 0) {
            return 1;
        }

        // If the value is already computed, return it
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        // Compute the number of paths from the cell above
        int up = sol(obs, m - 1, n, dp);
        
        // Compute the number of paths from the cell to the left
        int left = sol(obs, m, n - 1, dp);
        
        // Store the result in dp table and return it
        return dp[m][n] = up + left;
    }

    // Main function to find unique paths in m x n grid with obstacles
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();
        
        // If the starting or ending cell has an obstacle, return 0
        if (obs[0][0] == 1 || obs[m-1][n-1] == 1) {
            return 0;
        }

        // Initialize dp table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Call the recursive function starting from bottom-right corner
        return sol(obs, m - 1, n - 1, dp);
    }
};
