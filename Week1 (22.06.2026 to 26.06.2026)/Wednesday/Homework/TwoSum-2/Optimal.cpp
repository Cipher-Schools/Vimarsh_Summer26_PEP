#include <iostream>
#include <vector>

std::vector<int> twoSumOptimal(std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int current_sum = numbers[left] + numbers[right];

        if (current_sum == target) {
            // Return 1-indexed positions as required by the problem
            return {left + 1, right + 1};
        } 
        else if (current_sum < target) {
            // Sum is too small, move left pointer to increase sum
            left++;
        } 
        else {
            // Sum is too big, move right pointer to decrease sum
            right--;
        }
    }
    return {}; // Fallback empty vector (guaranteed exactly one solution though)
}

int main() {
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSumOptimal(numbers, target);

    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}