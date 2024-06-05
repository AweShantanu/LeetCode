class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        map<int,vector<int>> mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flag=true;
        for(auto &it:mp)
        {
            if(flag==true)
            {
                reverse(it.second.begin(),it.second.end());
            }
            for(int &num:it.second)
            {
                res.push_back(num);
            }
            
            flag=!flag;
        }
        return res;
        
        
    }
};