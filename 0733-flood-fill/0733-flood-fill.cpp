#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to perform DFS and fill the image with the new color
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& img2, int newColor, int delRow[], int delCol[]) {
        img2[row][col] = newColor;  // Fill the current cell with the new color
        int n = image.size();       // Number of rows in the image
        int m = image[0].size();    // Number of columns in the image
        
        // Iterate over all possible directions (up, right, down, left)
        for (int i = 0; i < 4; i++) {
            int newRow = delRow[i] + row;
            int newCol = delCol[i] + col;
            // Check if the new position is within bounds, has the original color, and is not already colored with the new color
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == image[row][col]
                && img2[newRow][newCol] != newColor) {
                dfs(newRow, newCol, image, img2, newColor, delRow, delCol);  // Recur for the connected cell
            }
        }
    }

    // Function to apply flood fill algorithm to an image
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int col = image[sr][sc];           // Store the original color of the starting cell
        vector<vector<int>> img2 = image;  // Create a copy of the image to apply the changes
        
        // Direction arrays to move in four directions (up, right, down, left)
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        // Start the DFS from the initial cell
        dfs(sr, sc, image, img2, color, delRow, delCol);
        return img2;  // Return the modified image
    }
};
