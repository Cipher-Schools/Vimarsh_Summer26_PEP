class Solution {
private:
    void generatePowerSet(int index, string &s, string current, vector<string>& result) {
        // Base case
        if (index == s.length()) {
            if (!current.empty()) { // GFG usually expects non-empty subsets
                result.push_back(current);
            }
            return;
        }
        
        // Choice 1: Include s[index]
        generatePowerSet(index + 1, s, current + s[index], result);
        
        // Choice 2: Exclude s[index]
        generatePowerSet(index + 1, s, current, result);
    }

public:
    vector<string> AllPossibleStrings(string s) {
        vector<string> result;
        
        // Step 1: Sort the string to ensure combinations are generated lexicographically
        sort(s.begin(), s.end());
        
        generatePowerSet(0, s, "", result);
        
        // Step 2: Sort the final result list to put everything in proper dictionary order
        sort(result.begin(), result.end());
        
        return result;
    }
};