#include <vector>
#include <queue>

class Solution {
public:
    int minStoneSum(std::vector<int>& piles, int k) {
        int n = piles.size();
        std::priority_queue<int> pq;
        
        // Push all piles into the max heap
        for (int i = 0; i < n; i++) {
            pq.push(piles[i]);
        }
        
        // Perform the operation k times
        while (k > 0) {
            int a = pq.top();
            pq.pop();
            a = a - a / 2; // Reduce the pile by half (integer division rounds down)
            pq.push(a);
            k--;
        }
        
        // Sum up the remaining stones
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};
