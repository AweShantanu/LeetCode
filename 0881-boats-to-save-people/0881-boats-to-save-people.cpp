class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats=0;
        int n=people.size();
        int i=0,j=n-1;
        sort(begin(people),end(people));
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                 boats++;
                i++;
                j--;
                
            }   
            
            else{
                j--;
                boats++;
            }
        }
        return boats;
    }
};