class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for (decltype(words.size()) i = 0; i != words.size(); ++i) {
            auto res = std::mismatch(pref.begin(), pref.end(), words[i].begin());
            if (res.first == pref.end()) {
                ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
