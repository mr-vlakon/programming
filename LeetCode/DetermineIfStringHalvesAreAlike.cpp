class Solution {
public:
    
    bool halvesAreAlike(string s) {
        unordered_map<char, size_t> um1;
        for (decltype(s.size()) i = 0; i != s.size() / 2; ++i) {
            ++um1[s[i]];
        }
        
        unordered_map<char, size_t> um2;
        for (decltype(s.size()) i = s.size() / 2; i != s.size(); ++i) {
            ++um2[s[i]];
        }
        
        unordered_set<char> us{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int cnt1 = 0;
        for (const auto &e: um1) {
            if (us.find(e.first) != us.cend())
                cnt1 += e.second;
        }
        
        int cnt2 = 0;
        for (const auto &e: um2) {
            if (us.find(e.first) != us.cend())
                cnt2 += e.second;
        }
        
        return cnt1 == cnt2;
    }
};

int main() {
  
 
  return 0;
}
