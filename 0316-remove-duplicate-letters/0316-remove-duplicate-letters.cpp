class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        int n=s.length();
        vector<int> lastIndex(26);
        vector<bool> occurance(26,false);
        //last index wala string bharo
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            lastIndex[ch-'a']=i;
        }
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            int index=ch-'a';
            if(occurance[index]==true)
            continue;
            while(result.length()>0 && result.back()>ch && lastIndex[result.back()-'a']>i)
            {
                occurance[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(ch);
            occurance[index]=true;
        }
        return result;
        
        
    }
};