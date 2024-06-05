class Solution {
public:
    vector<int> res;
    void sumOfEven(vector<int>& nums,int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                sum+=nums[i];
            }
        }
        res.push_back(sum);
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int val=queries[i][0];
            int index=queries[i][1];
            nums[index]=nums[index]+val;
            sumOfEven(nums,n);
        }
        return res;
        
    }
};