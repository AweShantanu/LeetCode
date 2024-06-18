class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count=0;
        long long n=s.size();
        long long res=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                if(count>0)
                {
                    res+=count;
                }
                count++;
                res+=1;
                
                    
            }
            
        }
        return res;
    }
};