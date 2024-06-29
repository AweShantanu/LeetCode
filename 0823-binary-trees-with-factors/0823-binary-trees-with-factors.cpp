class Solution {
public:
    int MOD=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int,long long> mp;
        mp[arr[0]]=1;
        long count=0;
        for(int i=1;i<arr.size();i++)
        {
            int root=arr[i];
            mp[root]=1;
            for(int j=0;j<i;j++)
            {
                int le=arr[j];
                if(root%le==0 && mp.find(root/le)!=mp.end())
                {
                    mp[root]+=mp[le]*mp[root/le];
                }
            }
            
        }
        for(auto &i:mp)
        {
            count+=i.second;
        }
        return count %MOD;
        
    }
};