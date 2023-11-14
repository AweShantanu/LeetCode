class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26,0);
        vector<int> upper(26,0);
        string ans;
        for(int i=0; i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                lower[s[i]-'a']++;
                s[i]='&';
            }
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                upper[s[i]-'A']++;
                s[i]='&';
            }
            
        }
        for(int j=0;j<26;j++)
        {
            char c='A'+j;
            while(upper[j])
            {
                ans+=c;
                upper[j]--;
                
            }
        }
        for(int j=0;j<26;j++)
        {
            char c='a'+j;
            while(lower[j])
            {
                ans+=c;
                lower[j]--;
                
            }
        }
        int first=0,second=0;
        while(second<ans.size())
        {
            if(s[first]=='&')
            {
                s[first]=ans[second];
                second++;
                
            }
            first++;
            
        }
        return s;
        

    }
};