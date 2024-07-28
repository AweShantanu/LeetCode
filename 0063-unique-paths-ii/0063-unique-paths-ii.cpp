class Solution {
public:
    
    int sol(vector<vector<int>>& obs,int m,int n,vector<vector<int>> &dp)
    {
        if(m==0 && n==0)
            return 1;
        
        if(m<0 || n<0 ||  obs[m][n]==1)
            return 0;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int up=sol(obs,m-1,n,dp);
        int left=sol(obs,m,n-1,dp);
        return dp[m][n]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m=obs.size();
        int n=obs[0].size();
        if(obs[0][0]==1)
            return 0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return sol(obs,m-1,n-1,dp);
    }
};