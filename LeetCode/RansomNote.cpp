class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, size_t> um1;
        for (const auto &e: ransomNote)
            ++um1[e];
        
        unordered_map<char, size_t> um2;
        for (const auto &e: magazine)
            ++um2[e];
        
        for (const auto &e: um1) {
            auto it = um2.find(e.first);
            if (it == um2.cend()) return false;
            if (e.second > it->second)
                return false;
        }
        
        return true;
        
    }
};

int main() {
  
  
  
  return 0;  
}
