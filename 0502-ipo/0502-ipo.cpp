#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> vec(n);
        priority_queue<int> pq;

        // Create a vector of pairs where each pair is (capital[i], profits[i])
        for (int i = 0; i < n; i++) {
            vec[i] = {capital[i], profits[i]};
        }
        
        // Sort the vector based on the capital required
        sort(vec.begin(), vec.end());
        
        int i = 0;
        // Iterate up to k times or until no more projects can be completed
        while (k-- > 0) {
            // Push all the projects into the priority queue that can be completed with the current capital
            while (i < n && vec[i].first <= w) {
                pq.push(vec[i].second);
                i++;
            }
            // If no more projects can be completed, break out of the loop
            if (pq.empty()) break;
            // Add the profit of the project with the highest profit
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};
