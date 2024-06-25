class Solution {
public:
    int numberOfMatches(int n) {
        int matched=0;
        
        while(n>1)
        {
             if(n%2==0)
             {
                  matched+=n/2;
                  n=n/2;
             }
            else{
                matched+=(n-1)/2;
                n=(n-1)/2+1;
            }
               
        } 
        return matched;
           
        
    }
};