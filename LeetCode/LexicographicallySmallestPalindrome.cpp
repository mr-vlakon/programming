class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        char tmp;
        while (start < end) {
            if (s[start] != s[end]) {
                tmp = min(s[start], s[end]);
                s[start] = tmp;
                s[end] = tmp;
            }
            ++start;
            --end;
        }
        return s;
    }
};

int main() {
  
  
  
  
  return 0;  
}
