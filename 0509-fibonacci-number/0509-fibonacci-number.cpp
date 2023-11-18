class Solution {
public:
    // int recSolve(int n)
    // {
    //     if(n==1 || n==0)
    //         return n;
    //     int ans=recSolve(n-1)+recSolve(n-2);
    //     return ans;
    // }
    
    //DP
    int topDown(int n, vector<int>& dp)
    {
        if(n==1 || n==0)
            return n;
        
        //step 3: check if ans is already exost
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        //step 2: replace ans with dp[n]
        dp[n]=topDown(n-1,dp)+topDown(n-2,dp);
        return dp[n];
    }
    
    int fib(int n) {
        // int ans=recSolve(n);
        // return ans;
        
        //step 1: create DP array
        vector<int> dp(n+1,-1);
        int ans=topDown(n,dp);
        return ans;
    }
};