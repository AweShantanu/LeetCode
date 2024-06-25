class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();      // Number of rows in the original matrix
        int m = matrix[0].size();   // Number of columns in the original matrix

        // Create a new matrix with dimensions m x n for the transposed matrix
        vector<vector<int>> transposed(m, vector<int>(n));

        // Fill the transposed matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                transposed[j][i] = matrix[i][j];
            }
        }

        return transposed;  // Return the transposed matrix
    }
};
