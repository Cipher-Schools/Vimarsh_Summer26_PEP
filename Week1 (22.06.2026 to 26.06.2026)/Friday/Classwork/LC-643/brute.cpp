// This works logically but is highly inefficient for large k
double findMaxAverageBrute(std::vector<int>& nums, int k) {
    double max_avg = -1e9; // Initialize with a very small number
    for (int i = 0; i <= nums.size() - k; i++) {
        double current_sum = 0;
        for (int j = i; j < i + k; j++) {
            current_sum += nums[j];
        }
        max_avg = std::max(max_avg, current_sum / k);
    }
    return max_avg;
}