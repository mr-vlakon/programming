class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, size_t> um1, um2;
        for (const auto &c: s) {
            ++um1[c];
        }
        for (const auto &c: t) {
            ++um2[c];
        }
        return um1 == um2;
    }
};

int main() {
  
  return 0;  
}
