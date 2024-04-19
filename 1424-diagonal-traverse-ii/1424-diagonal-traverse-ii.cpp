class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> map; //row+col , vector
        int diagonal=0;
        for(int row= nums.size()-1;row>=0;row--)
        {
            for(int col=0;col<nums[row].size();col++)
            {
                map[row+col].push_back(nums[row][col]);
            }
        }
        vector<int> result;
        while(map.find(diagonal)!=map.end()){
            for(int& nums:map[diagonal])
            {
                result.push_back(nums);
            }
            diagonal++;
        }
        return result;
    }
};