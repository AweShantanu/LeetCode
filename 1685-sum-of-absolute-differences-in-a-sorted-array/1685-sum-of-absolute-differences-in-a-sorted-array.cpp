class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        //ak brute force approach hoga jisme ki o(n2) aa jaiga time com
        //but approach 2 hai jisme ham
        //ye karenge
        
        
        //result hai ye predefined 
        //res[i]=(nums[i]*i) - (0 to i-1 ka sum) + (i+1 to n-1 ka sum) - (nums[i] * (n-i-1))
        
        for(int i=0;i<n ;i++)
        {
            int leftSum=prefixSum[i]-nums[i];
            int rightSum=prefixSum[n-1]-prefixSum[i];
            res[i]=(nums[i]*i) - leftSum - (nums[i] * (n-i-1)) + rightSum; 
        }
        return res;
        
    }
};