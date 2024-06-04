class Solution {
public:
    vector<vector<int>> result;
    
    void twoSum(int sum,vector<int> &nums,int start,int end)
    {
        while(start<end)
        {
            if(sum>(nums[start]+nums[end]))
                start++;
            else if(sum<nums[start]+nums[end])
                end--;
            else{
                while(start<end && nums[start]==nums[start+1])
                    start++;
                while(start<end && nums[end]==nums[end-1])
                    end--;
                result.push_back({-sum,nums[start],nums[end]});
                start++;
                end--;
                
            }
            
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        {
            return {};
        }
        result.clear();
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int temp=nums[i];
            int res=-temp;
            twoSum(res,nums,i+1,n-1);
        }
        return result;
    }
};