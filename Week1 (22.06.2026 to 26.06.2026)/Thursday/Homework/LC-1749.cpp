#include <iostream>
#include <vector>
#include <algorithm>

int maxAbsoluteSumPrefix(std::vector<int>& nums) {
    int current_prefix_sum = 0;
    int max_prefix = 0;
    int min_prefix = 0;

    for (int x : nums) {
        current_prefix_sum += x;
        
        // Keep track of the highest peak and lowest valley reached so far
        max_prefix = std::max(max_prefix, current_prefix_sum);
        min_prefix = std::min(min_prefix, current_prefix_sum);
    }

    // The maximum range between the peak and valley is our answer
    return max_prefix - min_prefix;
}

int main() {
    std::vector<int> nums = {1, -3, 2, 3, -4};

    int result = maxAbsoluteSumPrefix(nums);

    // Expected Output: 5 (Subarray [2, 3] gives 5, or [1, -3] gives -2 -> abs is 2, etc. 
    // Wait, the subarray [1, -3, 2, 3, -4] has components. Let's look: [2, 3] = 5.)
    std::cout << "Maximum absolute subarray sum: " << result << std::endl;
    return 0;
}