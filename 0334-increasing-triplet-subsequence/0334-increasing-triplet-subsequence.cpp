class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> less(n,0);
        less[0]=nums[0];
        vector<int> more(n,0);
        more[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>less[i-1])
                less[i]=less[i-1];
            else{
                less[i]=nums[i];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<more[i+1])
                more[i]=more[i+1];
            else{
                more[i]=nums[i];
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>less[i] && nums[i]<more[i])
                return true;
        }
        return false;
        
    }
};