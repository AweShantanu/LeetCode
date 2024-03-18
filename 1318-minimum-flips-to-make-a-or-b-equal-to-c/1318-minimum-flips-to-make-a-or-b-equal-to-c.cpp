class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int flips=0;
        while(a!=0 || b!=0 || c!=0) //right shift marte marte sara number hi khatam ho jaiga to isliye
        {
            if((c & 1)==1)
           {
                if((a&1)==0 && (b&1)==0)
                {
                    flips++;
                }
            
           }
            else
            { //agar c ka bit 0 h0ga to
                if((a&1)==1)
                {
                    flips++;
                }
                if((b&1)==1)
                    flips++;
                
            }
            
            a>>=1;
            b>>=1;
            c>>=1;
            
        }
        return flips;
    }
    
};