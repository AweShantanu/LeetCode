class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> mp;
        vector<int> res;
        int n=changed.size();
        if(n%2!=0)
            return {};
        sort(changed.begin(),changed.end());
        for(auto &i:changed)
        {
            mp[i]++;
            
        }
        for(int i=0;i<n;i++)
        {
            int mul=changed[i]*2;
            
            if(mp[changed[i]]==0)
                continue;
            if(mp[mul]==0)
                return {};
            mp[mul]--;
            mp[changed[i]]--;
            res.push_back(changed[i]);
        }
        return res;
        
    }
};