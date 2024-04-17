class Solution {
public:
    int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            map[nums[i]]=i;
        }
        int result=1;
        int i=0;
        int j=0;
        j=max(j,map[nums[i]]);
        while(i<n)
        {
            if(i>j)
            {
                result=(result*2)%M;
                
            }
            j=max(j,map[nums[i]]);
            i++;
            
        }
        return result;
    }
};