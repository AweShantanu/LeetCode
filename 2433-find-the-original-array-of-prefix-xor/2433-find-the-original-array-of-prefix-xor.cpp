class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int m=pref.size();
        vector<int> ans;
        ans.push_back(pref[0]);  //as pehle element same hoga kyki i-1 to hogha nahi
        for(int i=1;i<m;i++)
        {
            ans.push_back(pref[i]^pref[i-1]);
        }
        return ans;
    }
};