class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> um1;
        for (const auto &e: word1) {
            ++um1[e];
        }
        
        unordered_map<char, int> um2;
        for (const auto &e: word2) {
            ++um2[e];
        }
        
        for (const auto &e: um1) {
            auto it = um2.find(e.first);
            if (it == um2.cend()) {
                if (e.second > 3)
                    return false;
            } else {
                if (abs(e.second - it->second) > 3)
                    return false;
            }
        }
        
        for (const auto &e: um2) {
            auto it = um1.find(e.first);
            if (it == um1.cend()) {
                if (e.second > 3)
                    return false;
            } else {
                if (abs(e.second - it->second) > 3)
                    return false;
            }
        }
        
        
        return true;
        
    }
};

int main() {
  
  
  
  return 0;  
}
