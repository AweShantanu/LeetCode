class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        
        int len=0;
        
        
        for(string &ch : words)
        {
            vector<int> chars1(26,0);
        
            vector<int> chars2(26,0);
            bool bo=true;
            for(int i=0;i<chars.length();i++)
            {
                chars1[chars[i]-'a']++;
            }
            for(int j=0;j<ch.length();j++)
            {
                chars2[ch[j]-'a']++;
            }
            for(int h=0;h<26;h++)
            {
                if(chars2[h]>chars1[h])
                {
                    bo=false;
                    break;
                }    
            }
            if(bo)
            {
                len=len+ch.length();
                
            }
            
        }
        return len;
    }
};