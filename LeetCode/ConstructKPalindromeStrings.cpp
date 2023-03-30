class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        unordered_map<char, int> um;
        for (const auto &e: s) {
            um[e]++;
        }
        int cnt = 0;
        for (const auto &e: um) {
            if ((e.second % 2) == 1)
                ++cnt;
        }    
        return cnt <= k;
    }
};

int main() {
  
  
  return 0;  
}
