#include <iostream>
#include <string>
#include <vector>
#include <climits>

std::string minWindow(std::string s, std::string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) {
        return "";
    }

    // Hash maps using frequency vectors for ASCII characters
    std::vector<int> target_freq(128, 0);
    std::vector<int> window_freq(128, 0);

    for (char c : t) {
        target_freq[c]++;
    }

    // Count how many unique characters in t need to be satisfied
    int unique_needed = 0;
    for (int i = 0; i < 128; i++) {
        if (target_freq[i] > 0) {
            unique_needed++;
        }
    }

    int left = 0;
    int match_count = 0; // Tracks how many unique characters meet their target frequency
    
    int min_len = INT_MAX;
    int start_idx = -1; // Stores the starting point of our best window

    for (int right = 0; right < s.length(); right++) {
        char right_char = s[right];
        window_freq[right_char]++;

        // If this character is part of t and its frequency matches the requirement
        if (target_freq[right_char] > 0 && window_freq[right_char] == target_freq[right_char]) {
            match_count++;
        }

        // Squeeze the window from the left as long as the window remains valid
        while (match_count == unique_needed) {
            int current_window_size = right - left + 1;
            
            // Update our minimum window track
            if (current_window_size < min_len) {
                min_len = current_window_size;
                start_idx = left;
            }

            char left_char = s[left];
            window_freq[left_char]--;

            // If dropping this character breaks our matching criteria, decrement match_count
            if (target_freq[left_char] > 0 && window_freq[left_char] < target_freq[left_char]) {
                match_count--;
            }
            
            left++; // Squeeze
        }
    }

    return (start_idx == -1) ? "" : s.substr(start_idx, min_len);
}

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";

    std::string result = minWindow(s, t);

    // Expected Output: "BANC"
    std::cout << "Minimum window substring is: \"" << result << "\"\n";
    return 0;
}