#include <string>
#include <vector>

int firstUniqChar(std::string s) {
    std::vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}