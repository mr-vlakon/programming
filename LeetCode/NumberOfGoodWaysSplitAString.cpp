class Solution {
public:
    int numSplits(string s) {
        int i = 0;
        int cnt = 0;
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        for (const auto &e: s) {
            ++um2[e];
        }
        
        while (i != s.size()) {
            ++um1[s[i]];
            --um2[s[i]];
            if (um2[s[i]] <= 0) {
                um2.erase(s[i]);
            }
            
            if (um1.size() == um2.size()) ++cnt;
            ++i;
        }
        
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
