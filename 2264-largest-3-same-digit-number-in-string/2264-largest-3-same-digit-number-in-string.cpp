#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string largestTriplet = "";  // To store the largest triplet found

        // Iterate through the string starting from the 3rd character (index 2)
        for (int i = 2; i < num.length(); i++) {
            // Check if the current character and the previous two characters are the same
            if (num[i] == num[i-1] && num[i] == num[i-2]) {
                string triplet = num.substr(i-2, 3);  // Extract the triplet
                // Update the largestTriplet if the current triplet is greater
                if (triplet > largestTriplet) {
                    largestTriplet = triplet;
                }
            }
        }

        return largestTriplet;  // Return the largest triplet or an empty string if none found
    }
};
