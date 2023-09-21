class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ms;
        for(auto str: strs)
        {
            string s=str;
            sort(s.begin(),s.end());
            ms[s].push_back(str);
            
        }
        vector<vector<string>> ans;
        for(auto it=ms.begin(); it!=ms.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};