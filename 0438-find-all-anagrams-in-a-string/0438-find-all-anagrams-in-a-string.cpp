class Solution {
public:
    bool allZeros(vector<int> &res)
    {
        
        for(auto &i: res)
        {
            if(i!=0)
                return false;
            
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res(26,0);
        int k=p.size();
        
        for(int i=0;i<k;i++)
        {
            char ch=p[i];
            res[ch-'a']++;
        }
        int i=0;
        int j=0;
        vector<int> result;
    
        int n=s.size();
        
        
        while(j<n)
        {
            res[s[j]-'a']--;
            if((j-i+1)==k)
            {
                if(allZeros(res))
                {
                    result.push_back(i);
                }
                res[s[i]-'a']++;
                i++;
            }
            j++;
            
            
        }
        return result;
    }
};