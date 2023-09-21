class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
        }
        
        
        //ab ham most frequent character niklange 
        int max=INT_MIN;
        char mostFreCha;
        for(int i=0;i<26;i++)
        {
            if(hash[i]>max){
                max=hash[i];
                mostFreCha=i+'a';
            }
        }
        
        //ab ham place karenge 
        int index=0;
        while(max > 0 && index< s.size())
        {
            s[index]=mostFreCha;
            max--;
            index+=2;
            
        }
        if(max!=0)
           return "";
        hash[mostFreCha -'a']=0;
        for(int i=0;i<26;i++)
        {
            while(hash[i]>0)
            {
                index=index>=s.size() ? 1 : index;
                hash[i]--;
                s[index]=i+'a';
                index+=2;
            }
            
        }
        return s;
        
    }
};