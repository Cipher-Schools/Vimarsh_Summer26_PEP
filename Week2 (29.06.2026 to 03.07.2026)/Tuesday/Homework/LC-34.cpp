#include <iostream>
#include <vector>

// Helper function to find either the first or last occurrence of a target
int findBound(const std::vector<int>& nums, int target, bool isFirst) {
    int low = 0;
    int high = nums.size() - 1;
    int bound = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            bound = mid; // Record the index as a potential answer
            
            if (isFirst) {
                high = mid - 1; // Keep looking left for the absolute first position
            } else {
                low = mid + 1;  // Keep looking right for the absolute last position
            }
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return bound;
}

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int first = findBound(nums, target, true);
    
    // Optimization: If the first position doesn't exist, the last won't either
    if (first == -1) {
        return {-1, -1};
    }
    
    int last = findBound(nums, target, false);
    return {first, last};
}

int main() {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    std::vector<int> result = searchRange(nums, target);

    // Expected Output: [3, 4]
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}