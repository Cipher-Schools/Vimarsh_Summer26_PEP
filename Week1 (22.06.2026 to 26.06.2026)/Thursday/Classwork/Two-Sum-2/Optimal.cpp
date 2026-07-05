#include <iostream>
#include <vector>

std::vector<int> twoSumOptimal(std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int current_sum = numbers[left] + numbers[right];

        if (current_sum == target) {
            // Problem requires 1-indexed output
            return {left + 1, right + 1};
        } 
        else if (current_sum < target) {
            // Sum is too small, shift left pointer rightward to get a larger value
            left++;
        } 
        else {
            // Sum is too big, shift right pointer leftward to get a smaller value
            right--;
        }
    }
    return {}; 
}

int main() {
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSumOptimal(numbers, target);

    // Expected Output: [1, 2]
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}