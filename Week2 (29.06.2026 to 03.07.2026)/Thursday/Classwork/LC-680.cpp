#include <string>

bool isSubPalindrome(const std::string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(std::string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            // Try skipping either the left character or the right character
            return isSubPalindrome(s, left + 1, right) || isSubPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}