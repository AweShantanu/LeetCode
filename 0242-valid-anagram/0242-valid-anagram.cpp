class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqTa[256]={0};
        for(int i=0;i<s.length();i++)
        {
            freqTa[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            freqTa[t[i]]--;
        }
        for(int i=0;i<256;i++)
        {
            if(freqTa[i]!=0)
            {
                return false;
            }
            
        }
        return true;
    }
};