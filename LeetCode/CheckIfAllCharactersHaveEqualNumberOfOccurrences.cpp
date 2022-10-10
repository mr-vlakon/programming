class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, size_t> um;
        for (const auto &e: s) {
            ++um[e];
        }
        size_t x = um.cbegin()->second;
        for (const auto &e: um) {
            if (e.second != x)
                return false;
        }
        return true;
        
    }
};

int main() {
  
  
  return 0;  
}
