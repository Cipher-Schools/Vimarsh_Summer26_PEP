#include <string>
#include <algorithm>

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(std::string s, int k) {
    int current_vowels = 0;
    
    // Compute vowels for the first window of size k
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) current_vowels++;
    }
    
    int max_vowels = current_vowels;
    
    // Slide window across the remaining characters
    for (int i = k; i < s.length(); i++) {
        if (isVowel(s[i])) current_vowels++;      // Add incoming char
        if (isVowel(s[i - k])) current_vowels--;  // Remove outgoing char
        
        max_vowels = std::max(max_vowels, current_vowels);
    }
    return max_vowels;
}