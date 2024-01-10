// class Solution {
// public:
//     int result;
//     int n,m;
//     int countOfObs;
//     vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
//     void solve(vector<vector<int>>& grid , int i, int j , int count)
//     {
//         if(i<0 || i>m || j<0 || j>n || grid[i][j]==-1)
//             return ;
//         if(grid[i][j]==2){
//             if(count ==countOfObs)
//             {
//                 result++;
//                 return ;
//             }
//         }
//         grid[i][j]=-1;
//         for(auto &dir : directions)
//         {
//             int new_i=i+dir[0];
//             int new_j=j+dir[1];
//             solve(grid,new_i,new_j,count+1);
//         }
//         grid[i][j]=0;
//     }
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         result=0;
//         m=grid.size();
//         n=grid[0].size();
//         int st_i=0;
//         int st_j=0;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]==1)
//                 {
//                     st_i=i;
//                     st_j=j;
//                 }
//                 if(grid[i][j]==0)
//                 {
//                     countOfObs++;
//                 }   
//             }
//         }
//         countOfObs=+1;
//         int count=0;
//         solve(grid,st_i,st_j,count);
//         return result;
//     }
// };
#include <vector>

class Solution {
public:
    int result;
    int n, m;
    int countOfObs;
    std::vector<std::vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(std::vector<std::vector<int>>& grid, int i, int j, int count) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
            return;

        if (grid[i][j] == 2) {
            if (count == countOfObs) {
                result++;
            }
            return;
        }

        grid[i][j] = -1;

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            solve(grid, new_i, new_j, count + 1);
        }

        grid[i][j] = 0;
    }

    int uniquePathsIII(std::vector<std::vector<int>>& grid) {
        result = 0;
        m = grid.size();
        n = grid[0].size();
        int st_i = 0;
        int st_j = 0;
        countOfObs = 0;  // Initialize countOfObs to zero

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    st_i = i;
                    st_j = j;
                }
                if (grid[i][j] == 0) {
                    countOfObs++;
                }
            }
        }

        countOfObs += 1;

        int count = 0;
        solve(grid, st_i, st_j, count);

        return result;
    }
};

