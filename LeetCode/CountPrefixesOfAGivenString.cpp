class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for (decltype(words.size()) i = 0; i != words.size(); ++i) {
            auto res = std::mismatch(words[i].begin(), words[i].end(), s.begin());
            if (res.first == words[i].end()) {
                ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
  
  return 0;  
}
