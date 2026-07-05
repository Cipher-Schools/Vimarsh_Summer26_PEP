#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    // Unordered Set uses an internal hash table for O(1) lookups
    std::unordered_set<int> seen_numbers;

    for (int num : nums) {
        // If the number is already present in our set tracker
        if (seen_numbers.find(num) != seen_numbers.end()) {
            return true; 
        }
        
        // Otherwise, insert it into the history set
        seen_numbers.insert(num);
    }

    return false;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 1};
    std::vector<int> nums2 = {1, 2, 3, 4};

    // Expected Output: 1 (True)
    std::cout << "Array 1 result: " << containsDuplicate(nums1) << "\n";
    
    // Expected Output: 0 (False)
    std::cout << "Array 2 result: " << containsDuplicate(nums2) << "\n";

    return 0;
}