#include <iostream>
#include <vector>
#include <cmath> // For std::abs

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> duplicates;

    for (int i = 0; i < nums.size(); i++) {
        // Use the absolute value of the current element to determine the target index
        int target_index = std::abs(nums[i]) - 1;

        // If the value at the target index is negative, we've seen this number before
        if (nums[target_index] < 0) {
            duplicates.push_back(std::abs(nums[i]));
        } else {
            // Otherwise, flip the sign to negative to mark it as visited
            nums[target_index] = -nums[target_index];
        }
    }

    return duplicates;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    std::vector<int> result = findDuplicates(nums);

    // Expected Output: 2 3
    std::cout << "Duplicate elements: ";
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}