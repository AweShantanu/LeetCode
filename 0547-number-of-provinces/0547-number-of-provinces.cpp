#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to perform DFS traversal
    void sol(int i, vector<int> &visited, vector<vector<int>>& isConnected, int n) {
        visited[i] = 1;  // Mark the current node as visited
        for (int j = 0; j < n; j++) {
            // If there's a direct connection and the node hasn't been visited
            if (isConnected[i][j] == 1 && visited[j] == 0) {
                sol(j, visited, isConnected, n);  // Recur for the connected node
            }
        }
    }

    // Function to count the number of connected components (provinces) in the graph
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();  // Number of nodes (cities) in the graph
        vector<int> visited(n, 0);   // Vector to keep track of visited nodes
        int count = 0;               // Counter for the number of provinces

        // Iterate through each node in the graph
        for (int i = 0; i < n; i++) {
            // If the node hasn't been visited, it's a new province
            if (visited[i] == 0) {
                count++;  // Increment the province counter
                sol(i, visited, isConnected, n);  // Perform DFS to mark all nodes in this province
            }
        }
        return count;  // Return the total number of provinces found
    }
};
