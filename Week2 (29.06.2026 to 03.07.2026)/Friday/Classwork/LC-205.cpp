#include <string>
#include <vector>

bool isIsomorphic(std::string s, std::string t) {
    // Map character positions to their first seen index (+1 to distinguish from initial 0)
    std::vector<int> mapS(256, 0);
    std::vector<int> mapT(256, 0);
    
    for (int i = 0; i < s.length(); i++) {
        if (mapS[s[i]] != mapT[t[i]]) {
            return false;
        }
        mapS[s[i]] = i + 1;
        mapT[t[i]] = i + 1;
    }
    return true;
}