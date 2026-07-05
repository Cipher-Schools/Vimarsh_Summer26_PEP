#include <string>
#include <vector>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    // Map characters to their last seen index
    std::vector<int> last_seen(256, -1);
    int max_len = 0;
    int left = 0;

    for (int right = 0; right < s.length(); right++) {
        // If the character was seen inside the current window, move the left boundary
        if (last_seen[s[right]] >= left) {
            left = last_seen[s[right]] + 1;
        }

        last_seen[s[right]] = right;
        max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
}