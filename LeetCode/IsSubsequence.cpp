class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (decltype(t.size()) j = 0; j != t.size(); ++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == s.size();
    }
};

int main() {
  
  
  return 0;  
}
