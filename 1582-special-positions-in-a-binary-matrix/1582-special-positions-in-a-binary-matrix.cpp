class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> rows(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    rows[i]++;
                    col[j]++;
                }
            }
        }
        int result=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                    continue;
                if(rows[i]==1 && col[j]==1)
                    result++;
            }
        }
        return result;
        
    }
};