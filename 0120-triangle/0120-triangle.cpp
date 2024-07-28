class Solution {
public:
    // Recursive function to find the minimum path sum
    // Parameters: i - current row, j - current column, t - triangle, dp - memoization table
    int sol(int i, int j, vector<vector<int>>& t, vector<vector<int>>& dp) {
        // Base case: if we reach the last row
        if (i == t.size() - 1) {
            return t[i][j];
        }

        // If the value is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Compute the minimum path sum from the cell directly below
        int down = t[i][j] + sol(i + 1, j, t, dp);
        
        // Compute the minimum path sum from the cell diagonally below to the right
        int right = t[i][j] + sol(i + 1, j + 1, t, dp);

        // Store the result in the dp table and return it
        return dp[i][j] = min(down, right);
    }

    // Main function to find the minimum path sum in the triangle
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Initialize dp table with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Call the recursive function starting from the top of the triangle
        return sol(0, 0, triangle, dp);
    }
};
