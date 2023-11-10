class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        int i=0,count=0;
        string temp="";
        while(i<s.size())
        {
            if(s[i]==' ')
            {
                int position =temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[position]=temp;
                temp.clear();
                count++;

            }
            else{
                temp+=s[i];
            }
            i++;
            
        }
        int position =temp[temp.size()-1]-'0';
        temp.pop_back();
        ans[position]=temp;
        temp.clear();
        count++;
        for(int i=1;i<=count;i++)
        {
            temp+=ans[i];
            temp+=' ';
        }
        temp.pop_back();
        return temp;
        
    }
};