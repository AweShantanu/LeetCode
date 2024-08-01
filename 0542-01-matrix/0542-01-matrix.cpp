#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Define the possible directions for movement (down, right, left, up)
    vector<vector<int>> direction{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();      // Number of rows
        int m = mat[0].size();   // Number of columns
        queue<pair<int, int>> q; // Queue to store cells for BFS
        
        // Initialize the answer matrix with -1, indicating unvisited cells
        vector<vector<int>> ans(n, vector<int>(m, -1));
        
        // Push all the cells with 0 into the queue and set their distance to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0; // Distance to the nearest 0 is 0 for cells with 0
                    q.push({i, j});
                }
            }
        }
        
        // Perform BFS to calculate distances
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            // Explore all four possible directions
            for (auto &dir : direction) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                
                // Check bounds and if the cell is unvisited (-1)
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && ans[new_i][new_j] == -1) {
                    q.push({new_i, new_j}); // Add the cell to the queue
                    ans[new_i][new_j] = ans[i][j] + 1; // Update the distance
                }
            }
        }
        
        return ans; // Return the matrix with updated distances
    }
};
