class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int row=0;row<rows;row++)
        {                                                           //for creation of cumulative matrrix
            for(int col=1;col<cols;col++)
            {
                matrix[row][col]+=matrix[row][col-1];
            }
        }
        
        //now we need to find the no of sub arrays with sum==target (leetcode 560)
        
        int result=0;
        for(int startCol=0;startCol<cols;startCol++)
        {
            for(int j=startCol;j<cols;j++)
            {
                unordered_map<int,int> map;
                int cumSum=0;
                map.insert({0,1});
                for(int row=0;row<rows;row++)   //niche move karne ke liye
                {
                    cumSum+=matrix[row][j] -(startCol>0 ? matrix[row][startCol-1] : 0);
                    if(map.find(cumSum-target)!=map.end())
                        result+=map[cumSum-target];
                    
                    
                    map[cumSum]++;
                }
            }
        }
        return result;
    }
};