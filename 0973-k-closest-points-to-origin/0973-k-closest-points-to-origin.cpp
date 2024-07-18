#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Using a max-heap to store the k closest points
        priority_queue<pair<int, vector<int>>> pq;

        for (int i = 0; i < points.size(); i++) {
            // Calculate the squared distance
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            // Push the point and its distance (negated to simulate a min-heap)
            pq.push({dist, points[i]});

            // If the size of the heap exceeds k, remove the farthest point
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Extract the k closest points from the heap
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
