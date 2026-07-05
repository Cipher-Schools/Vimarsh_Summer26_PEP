std::vector<int> twoSumBetter(std::vector<int>& numbers, int target) {
    int n = numbers.size();
    for (int i = 0; i < n; i++) {
        int complement = target - numbers[i];
        
        // Binary search for the complement in the remaining array
        int low = i + 1, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (numbers[mid] == complement) {
                return {i + 1, mid + 1};
            } else if (numbers[mid] < complement) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return {};
}