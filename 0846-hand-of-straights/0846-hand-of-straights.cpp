class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize)
        {
            return false;
        }
        map<int,int> mp;
        for(auto &i:hand)
        {
            mp[i]++;
        }
        
        while(!mp.empty())
        {
            int ele=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mp.find(ele+i)==mp.end())
                {
                    return false;
                }
                mp[ele+i]--;
        
                if(mp[ele+i]<1)
                {
                    mp.erase(ele+i);
                }
                
            }
            
        }
        return true;
        
    }
};