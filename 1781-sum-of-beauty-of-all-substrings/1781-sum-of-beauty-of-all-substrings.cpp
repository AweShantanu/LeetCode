class Solution {
public:
    int beautySum(string s) {
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int> ch(26);
            for(int j=i;j<s.size();j++)
            {
                ch[s[j]-'a']++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto &it:ch)
                {
                    if(it>=1)
                    {
                        maxi=max(maxi,it);
                        mini=min(mini,it);
                    }
                    
                }
                res+=maxi-mini;
            }
        }
        return res;
    }
};