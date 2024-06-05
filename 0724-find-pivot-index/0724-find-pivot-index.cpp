class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int leftSum=0;
        int totalSum=0;
        int rightSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum=totalSum+nums[i];
        }
        for(int i=0;i<n;i++)
        {
            leftSum=nums[i]+leftSum;
            rightSum=totalSum-leftSum;
            if(rightSum==leftSum-nums[i])
            {
                return i;
            }
            
        }
        return -1;
        
    }
};