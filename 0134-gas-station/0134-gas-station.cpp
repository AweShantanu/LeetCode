#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        // If total gas is less than total cost, it's impossible to complete the circuit
        if (totalGas < totalCost) {
            return -1;
        }

        // Find the starting station
        for (int i = 0; i < gas.size(); i++) {
            currentGas += gas[i] - cost[i];
            // If currentGas is negative, reset it and set the next station as the start
            if (currentGas < 0) {
                startStation = i + 1;
                currentGas = 0;
            }
        }

        return startStation;
    }
};
