class Solution {
public:
    bool isPalindrome(const string &s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        return isPalindrome(s) ? 1 : 2;
    }
};

int main() {
  
  
  return 0;  
}
