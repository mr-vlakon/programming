class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int cnt = 0;
        if (s.size() != goal.size()) return false;
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        for (int i = 0; i != s.size(); ++i) {
            um1[s[i]]++;
            um2[goal[i]]++;
            if (s[i] != goal[i])
                ++cnt;
        }
        if (um1 != um2)
            return false;
        if (cnt == 0) {
            for (const auto &e: um1) {
                if (e.second >= 2) return true;
            }
            return false;
        }
        return cnt == 2 ? true : false;
    }
};

int main() {
  
  
  return 0;  
}
