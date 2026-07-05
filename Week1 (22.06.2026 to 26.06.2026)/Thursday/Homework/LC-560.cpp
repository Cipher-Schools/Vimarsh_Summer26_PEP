#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySumOptimal(std::vector<int>& nums, int k) {
    // Map to store frequency of prefix sums: <prefix_sum, count>
    std::unordered_map<int, int> prefix_sums;
    
    int total_subarrays = 0;
    int current_sum = 0;
    
    // Base Case: A prefix sum of 0 has occurred exactly once 
    // (handles subarrays that equal k starting from index 0)
    prefix_sums[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
        current_sum += nums[i];

        // Check if (current_sum - k) exists in our map history
        int lookfor = current_sum - k;
        if (prefix_sums.find(lookfor) != prefix_sums.end()) {
            total_subarrays += prefix_sums[lookfor];
        }

        // Record the current running sum into the map history
        prefix_sums[current_sum]++;
    }

    return total_subarrays;
}

int main() {
    std::vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    int k = 7;

    int result = subarraySumOptimal(nums, k);

    // Expected Output: 4
    std::cout << "Total subarrays that sum up to " << k << ": " << result << std::endl;
    return 0;
}