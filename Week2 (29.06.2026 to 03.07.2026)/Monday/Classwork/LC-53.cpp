#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int maxSubArray(std::vector<int>& nums) {
    int max_sum = INT_MIN; // Tracks the overall maximum subarray sum seen so far
    int current_sum = 0;   // Tracks the sum of our current local subarray

    for (int i = 0; i < nums.size(); i++) {
        current_sum += nums[i];

        // Update the global maximum if our current subarray sum is better
        max_sum = std::max(max_sum, current_sum);

        // Greedy Step: If the running sum becomes negative, it will only hurt
        // the sum of any subsequent subarray. Discard it by resetting to 0.
        if (current_sum < 0) {
            current_sum = 0;
        }
    }

    return max_sum;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);

    // Expected Output: 6 (The subarray is [4, -1, 2, 1] which sums to 6)
    std::cout << "Maximum subarray sum is: " << result << std::endl;
    return 0;
}