class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result=0;
        for(int k=0;k<32;k++) //harr bit ko check karne ke liye hai ye loop
        {
            int count1=0;
            int count0=0;
            int temp=(1<<k);
            for(int &num : nums)
            {
                if((temp & num)==0)
                    count0++;
                else
                    count1++;
                
            }
            if(count1 %3==1)
                result=result|temp;
                
        }
        return result;
    }
};