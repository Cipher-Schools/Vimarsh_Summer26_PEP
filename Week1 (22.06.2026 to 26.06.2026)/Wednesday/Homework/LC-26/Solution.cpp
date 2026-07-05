#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    // Edge case: If the array is empty, there are 0 unique elements
    if (nums.empty()) {
        return 0;
    }

    int unique_tracker = 0; // Points to the last known unique element

    // The scanner loop starts from the second element (index 1)
    for (int scanner = 1; scanner < nums.size(); scanner++) {
        // If we find an element that is different from our last unique element
        if (nums[scanner] != nums[unique_tracker]) {
            unique_tracker++; // Move tracker to the next available slot
            nums[unique_tracker] = nums[scanner]; // Overwrite it with the new unique value
        }
    }

    // Since unique_tracker is 0-indexed, the total count of unique items is unique_tracker + 1
    return unique_tracker + 1;
}

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(nums);

    std::cout << "Number of unique elements: " << k << "\n";
    std::cout << "Modified array up to index k: ";
    for (int i = 0; i < k; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";

    return 0;
}