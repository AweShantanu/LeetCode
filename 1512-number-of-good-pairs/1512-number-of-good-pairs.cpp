class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count=0;
        for(auto &i: nums)
        {
            if(mp.find(i)!=mp.end())
            {
                count+=mp[i];
                mp[i]++;
            }
            else{
                mp[i]++;
            }
        }
        return count;
    }
};