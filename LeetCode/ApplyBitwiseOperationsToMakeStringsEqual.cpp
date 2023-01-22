class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if (s == target) {
            return true;
        }
        auto cnt1 = count(target.cbegin(), target.cend(), '0');
        auto cnt2 = count(s.cbegin(), s.cend(), '0');
        return (cnt1 != target.size()) && (cnt2 != s.size());
    }
};

int main() {
  
  
  
  return 0;  
}
