class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26);
        vector<int> freq2(26);
       
        for(char &ch: word1)
            freq1[ch-'a']++;
        for(char &ch: word2)
            freq2[ch-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if(freq1[i]==0 && freq2[i]==0)
                continue;
            if(freq1[i]!=0 && freq2[i]!=0)
                continue;
            return false;
            
        }
        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));
        return freq1==freq2;
    }
    
};