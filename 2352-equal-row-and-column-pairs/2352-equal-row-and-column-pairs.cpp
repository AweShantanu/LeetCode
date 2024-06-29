class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int> ,int> mp;
        int count=0;
        for(auto &i:grid)
        {
            mp[i]++;
        }
        for(int j=0;j<grid.size();j++)
        {
            vector<int> vec;
            
            for(int i=0;i<grid.size();i++)
            {
                int h=grid[i][j];
                vec.push_back(h);
                
            }
            if(mp.find(vec)!=mp.end())
            {
                count+=mp[vec];
            }
        }
        return count;
    }
};