#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        int m = grid[0].size(); // number of columns
        int n = grid.size(); // number of rows
        
        for (int ball = 0; ball < m; ball++) {
            int row = 0;
            int col = ball;
            bool atka = false;

            while (row < n) {
                if (grid[row][col] == 1) {
                    // Move right
                    if (col == m - 1 || grid[row][col + 1] == -1) {
                        atka = true;
                        break;
                    }
                    col++;
                } else {
                    // Move left
                    if (col == 0 || grid[row][col - 1] == 1) {
                        atka = true;
                        break;
                    }
                    col--;
                }
                row++;
            }

            if (atka) {
                res.push_back(-1);
            } else {
                res.push_back(col);
            }
        }

        return res;
    }
};
