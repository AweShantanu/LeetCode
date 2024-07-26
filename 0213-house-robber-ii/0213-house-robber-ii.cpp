class Solution {
public:
    int sol(const std::vector<int>& nums, int start, int end, std::vector<int>& dp) {
        if (start > end)
            return 0;
        
        if (dp[start] != -1)
            return dp[start];
        
        int take = nums[start] + sol(nums, start + 2, end, dp);
        int not_take = sol(nums, start + 1, end, dp);
        
        return dp[start] = std::max(take, not_take);
    }

    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return std::max(nums[0], nums[1]);

        std::vector<int> dp(n, -1);
        int robFirstPart = sol(nums, 0, n - 2, dp);

        std::fill(dp.begin(), dp.end(), -1);
        int robSecondPart = sol(nums, 1, n - 1, dp);

        return std::max(robFirstPart, robSecondPart);
    }
};