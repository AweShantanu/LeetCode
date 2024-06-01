class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<P ,vector<P> , greater<P>> pq;
        unordered_map<int,int> mp;
        for(int i=0; i<n ; i++)
        {
            mp[nums[i]]++;
            
        }
        for(auto &it: mp)
        {
            int first=it.first;
            int second=it.second;
            pq.push({second,first});
            if(pq.size()>k)
            {
                
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};