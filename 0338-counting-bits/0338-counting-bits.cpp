class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if(n==0)
            return ans;
        ans[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
                ans[i]=ans[i/2];
            else
                ans[i]=ans[i/2]+1;
        }
        return ans;
        
    }
};
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n+1);
//         for(int i=0;i<n+1;i++)
//         {
//             ans[i]=__builtin_popcount(i);
//         }
//         return ans;
//     }
// };