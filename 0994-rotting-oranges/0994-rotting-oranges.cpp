#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Direction vectors for moving in the grid (up, right, down, left)
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        queue<pair<pair<int, int>, int>> q; // Queue to store the cell coordinates and time
        int time = 0;  // To keep track of the time required to rot all oranges

        // Initialize the queue with all initially rotten oranges and mark them in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});  // Push the rotten orange with time 0
                }
            }
        }

        // Perform BFS to rot adjacent fresh oranges
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            // Update the maximum time
            time = max(time, t);
            
            // Check all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int newR = r + dRow[i];
                int newC = c + dCol[i];
                
                // Check if the new position is within bounds and has a fresh orange
                if (newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1) {
                    grid[newR][newC] = 2;  // Mark the orange as rotten
                    q.push({{newR, newC}, t + 1});  // Push the new position with incremented time
                }
            }
        }

        // Check if any fresh oranges remain
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;  // Return -1 if there are any fresh oranges left
                }
            }
        }

        return time;  // Return the total time taken to rot all oranges
    }
};
