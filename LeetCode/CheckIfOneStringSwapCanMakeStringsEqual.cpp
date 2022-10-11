class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        
        unordered_map<char, size_t> um1;
        for (const auto &e: s1)
            ++um1[e];
        unordered_map<char, size_t> um2;
        for (const auto &e: s2)
            ++um2[e];
        for (const auto &e: um1) {
            auto it = um2.find(e.first);
            if (it == um2.cend()) return false;
            if (e.second != it->second)
                return false;
        }
        
        for (const auto &e: um2) {
            auto it = um1.find(e.first);
            if (it == um1.cend()) return false;
            if (e.second != it->second)
                return false;
        }
        
        for (decltype(s1.size()) i = 0; i != s1.size(); ++i) {
            if (s1[i] != s2[i])
                ++cnt;
        }
        return cnt == 2 || cnt == 0;
    }
};

int main() {
  
  
  return 0;  
}
