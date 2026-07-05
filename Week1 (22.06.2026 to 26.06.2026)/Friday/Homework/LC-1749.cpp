#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int maxAbsoluteSumKadane(std::vector<int>& nums) {
    int max_so_far = 0;
    int min_so_far = 0;
    
    int current_max = 0;
    int current_min = 0;

    for (int x : nums) {
        // Track maximum positive subarray
        current_max += x;
        max_so_far = std::max(max_so_far, current_max);
        if (current_max < 0) current_max = 0;

        // Track minimum negative subarray
        current_min += x;
        min_so_far = std::min(min_so_far, current_min);
        if (current_min > 0) current_min = 0;
    }

    return std::max(max_so_far, std::abs(min_so_far));
}