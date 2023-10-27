class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> arr;
        int s=0;
        int e=numbers.size()-1;
        for(int i=0;i<numbers.size()-1;i++)
        {
            if(numbers[s]+numbers[e]==target)
            {
                arr.push_back(s+1);
                arr.push_back(e+1);
                return arr;
                
            }
            else if(numbers[s]+numbers[e]<target)
            {
                s++;
            }
            else{
                e--;
            }
        }
        return arr;
    }
};