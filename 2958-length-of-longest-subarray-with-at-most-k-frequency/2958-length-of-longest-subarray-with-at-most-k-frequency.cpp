class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int n=nums.size();
        int i=0,j=0;
        int len=INT_MIN;

        while(j<n)
        {
            mp[nums[j]]++;
            while(mp[nums[j]]>k)
            {// ab i ko aage badhao tak tak jab tak ye j wala sahi na ho jai
                mp[nums[i]]--;
                i++;
                
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
        
    }
};