class Solution {
public:
    string reverseWords(string s) {
        //two pointer wla approach
        //yahan pe ham tokenizer wala approach se solve karenge
        stringstream ss(s);
        string token="";
        string result="";
        while(ss >> token) 
        {
            reverse(begin(token),end(token));
            result+=token+" ";
        }
        
        return result.substr(0,result.length()-1);
    }
};