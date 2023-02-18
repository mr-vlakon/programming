class Solution {
public:
    bool recursive(string &s, const vector<string> &wordDict) {
        if (s.size() == 0) {
            return true;
        }
        auto it = memo.find(s);
        if (it != memo.cend()) {
            return memo[s];
        }
        for (const auto &e: wordDict) {
            if (e.size() <= s.size()) {
                string tmp = string(s.cbegin(), s.cbegin() + e.size());
                if (tmp == e) {
                    string newS = string(s.cbegin() + e.size(), s.cend());
                    memo[s] |= recursive(newS, wordDict);
                }
            }
        }
        return memo[s];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return recursive(s, wordDict);
    }
private:
    unordered_map<string, bool> memo;
};

int main() {
  
  
  return 0;  
}
