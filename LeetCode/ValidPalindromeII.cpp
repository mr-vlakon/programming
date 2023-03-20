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
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                string s1 = string{s.cbegin() + start + 1, s.cbegin() + end + 1};
                string s2 = string{s.cbegin() + start, s.cbegin() + end};
                if (isPalindrome(s1)) {
                    return true;
                }
                if (isPalindrome(s2)) {
                    return true;
                }
                return false;                    
            } else {
                ++start;
                --end;
            }
        }
        return true;
    }
};

int main() {
  
  
  
  return 0;   
}
