#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> res(n, -1); // This will store the next greater elements for nums2
        
        // Iterate over nums2 to find the next greater element for each element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                res[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        
        // Map to store the next greater element for each element in nums2
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = res[i];
        }
        
        // Result vector for nums1
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = mp[nums1[i]];
        }
        
        return result;
    }
};
