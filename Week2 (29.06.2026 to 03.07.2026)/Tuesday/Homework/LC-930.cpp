#include <iostream>
#include <vector>

// Helper function to count subarrays with a sum less than or equal to the limit
int countAtMost(const std::vector<int>& nums, int limit) {
    if (limit < 0) return 0;
    
    int left = 0;
    int current_sum = 0;
    int count = 0;

    for (int right = 0; right < nums.size(); right++) {
        current_sum += nums[right];

        // Shrink the window if our sum exceeds the limit
        while (current_sum > limit) {
            current_sum -= nums[left];
            left++;
        }

        // Add the number of valid subarrays ending at 'right'
        count += (right - left + 1);
    }
    return count;
}

int numSubarraysWithSum(std::vector<int>& nums, int goal) {
    return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
}

int main() {
    std::vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int result = numSubarraysWithSum(nums, goal);

    // Expected Output: 4
    std::cout << "Total binary subarrays with sum " << goal << ": " << result << std::endl;
    return 0;
}