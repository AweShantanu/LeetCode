class Solution {
public:
    int findBits(int n)
    {
        int count =0;
        while(n!=0)
        {
            count+=(n&1);
            n>>=1;
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        
        auto lambda=[this](int&a,int&b)
        {
            int ca= findBits(a);
            int cb= findBits(b);
            if(ca==cb)
            {
                return a<b; //assending order mein chale jao
                
            }
            return ca<cb;  // jiska 1'sbits kam hoga wo pehle jaiga
            
        };
        
        sort(begin(arr),end(arr),lambda);
        
        
        
        
        return arr;
    }
};
