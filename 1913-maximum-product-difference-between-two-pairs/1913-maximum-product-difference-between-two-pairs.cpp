class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        sort(nums.begin(),nums.end());
        
        return nums[n-1]*nums[n-2] - (nums[0]*nums[1]);
        
    }
};