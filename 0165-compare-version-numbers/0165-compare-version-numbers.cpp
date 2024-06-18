#include <vector>
#include <string>
#include <sstream>

class Solution
{
public:
    std::vector<std::string> getTokens(const std::string& s)
    {
        std::stringstream ss(s);
        std::string token;
        std::vector<std::string> tokens;
        while (getline(ss, token, '.'))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    int compareVersion(const std::string& v1, const std::string& v2) {
        std::vector<std::string> ve1 = getTokens(v1);
        std::vector<std::string> ve2 = getTokens(v2);
        
        int n = ve1.size();
        int m = ve2.size();
        int i = 0;
        while (i < n || i < m)
        {
            int a = (i < n) ? stoi(ve1[i]) : 0;
            int b = (i < m) ? stoi(ve2[i]) : 0;
            
            if (a < b)
                return -1;
            else if (a > b)
                return 1;
            else
                i++;
        }
        return 0;
    }
};
