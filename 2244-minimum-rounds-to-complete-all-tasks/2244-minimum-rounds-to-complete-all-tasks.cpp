class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int task: tasks)
        {
            mp[task]++;
        }
        int count=0;
        for(auto i:mp)
        {
            if(i.second==1)
                return -1;
            else if(i.second%3==0)
                count=count+(i.second)/3;
            else if(i.second%3==1 || i.second%3==2)
                count=count+((i.second)/3+1);
            
        }
        return count;
    }
};