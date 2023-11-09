class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>v(26,0);
        for(int i=0;i<sentence.size();i++)
        {
            v[sentence[i]-'a']=1;
        }
        for(int j=0;j<v.size();j++)
        {
            if(v[j]!=1)
            {
                return false;
            }
        }
        return true;
    }
};