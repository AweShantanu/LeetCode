#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size();
        
        for (int i = 0; i < n; i++) {
            while (res.length() > 0 && k > 0 && res.back() > num[i]) {
                res.pop_back();
                k--;
            }
            if (res.size() > 0 || num[i] != '0') {
                res.push_back(num[i]);
            }
        }
        
        // If k is still greater than 0, remove the remaining characters from the end
        while (k > 0 && res.length() > 0) {
            res.pop_back();
            k--;
        }
        
        // Handle the case where the resulting string is empty
        if (res.empty()) {
            return "0";
        }

        return res;
    }
};

