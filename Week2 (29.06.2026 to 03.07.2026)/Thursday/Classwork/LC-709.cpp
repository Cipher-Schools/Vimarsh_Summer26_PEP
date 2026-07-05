#include <string>

std::string toLowerCase(std::string s) {
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; // or c = c | 32;
        }
    }
    return s;
}