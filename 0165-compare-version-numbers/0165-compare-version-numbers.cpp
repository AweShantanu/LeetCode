#include <vector>
#include <string>
#include <sstream>

class Solution
{
public:
    // This function takes a string and splits it into tokens based on the dot character.
    std::vector<std::string> getTokens(const std::string& s)
    {
        std::stringstream ss(s);
        std::string token;
        std::vector<std::string> tokens;

        // Split the string by '.' and store each part in the tokens vector.
        while (getline(ss, token, '.'))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    // This function compares two version strings v1 and v2.
    int compareVersion(const std::string& v1, const std::string& v2) {
        // Get the tokens (sub-versions) of v1 and v2.
        std::vector<std::string> ve1 = getTokens(v1);
        std::vector<std::string> ve2 = getTokens(v2);

        // Get the sizes of the token vectors.
        int n = ve1.size();
        int m = ve2.size();
        int i = 0;

        // Compare corresponding tokens of the two version strings.
        while (i < n || i < m)
        {
            // Convert the current token to integer, or use 0 if the token does not exist.
            int a = (i < n) ? std::stoi(ve1[i]) : 0;
            int b = (i < m) ? std::stoi(ve2[i]) : 0;

            // Compare the current tokens.
            if (a < b)
                return -1;  // v1 is less than v2
            else if (a > b)
                return 1;   // v1 is greater than v2
            else
                i++;        // Current tokens are equal, move to the next token.
        }
        return 0;  // All tokens are equal, v1 is equal to v2
    }
};
