class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        int result=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            result=max(result,(nums[i]-1)*(maxi-1));
            maxi=max(maxi,nums[i]);
        }
        return result;
    }
};