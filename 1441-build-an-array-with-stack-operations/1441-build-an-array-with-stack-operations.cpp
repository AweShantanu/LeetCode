class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> res;
        int i=0;
        int stream=1;
        while(i<target.size() && stream<=n)
        {
            res.push_back("Push");
            if(target[i]==stream)
            {
                i++;
                stream++;
            }
            else{
                res.push_back("Pop");
                stream++;
            }
        }
        return res;
    }
};