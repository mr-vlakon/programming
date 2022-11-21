class Solution {
public:
    bool isPalindrome(const string &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (const auto &e: words) {
            if (isPalindrome(e))
                return e;
        }
        
        return "";
    }
};

int main() {
  
  
  
  return 0;  
}
