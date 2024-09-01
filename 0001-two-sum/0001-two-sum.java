class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Loop through each element in the array
        for (int i = 0; i < nums.length; i++) {
            // Loop through the subsequent elements
            for (int j = i + 1; j < nums.length; j++) {
                // Check if the sum of the two elements equals the target
                if (nums[i] + nums[j] == target) {
                    // Return the indices of the two numbers
                    return new int[] { i, j };
                }
            }
        }
        // If no solution is found, return an empty array or null (depends on your design)
        return null; // or throw an exception
    }
}
